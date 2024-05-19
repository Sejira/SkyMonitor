#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QVBoxLayout>
#include <iostream>
#include <curl/curl.h>
#include <QTimer>

// Déclaration des variables globales
std::string response;
std::string api_key = "0d62869de0feb84e51be8aaf3e01d25b";
std::string ville = "Brest";
std::string code_postal = "29200";
std::string pays = "FR";

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append((char*)contents, total_size);
    return total_size;
}

class MyMainWindow : public QMainWindow {
public:
    MyMainWindow(QWidget* parent = nullptr) : QMainWindow(parent) {
        ui = new Ui::MainWindow;
        ui->setupUi(this);

        // Initialisez vos QLabel ici si nécessaire

        // Créez et configurez le QTimer
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MyMainWindow::fetchData);

        // Connectez le bouton de validation au slot correspondant
        connect(ui->submitButton, &QPushButton::clicked, this, &MyMainWindow::on_submitButton_clicked);

        // Démarrez le timer pour déclencher toutes les minutes
        timer->start(60000);  // 60000 millisecondes = 1 minute

        // Effectuez la première demande pour initialiser les données
        fetchData();
    }

    void updateWeatherInformation() {
        // Utilisez votre variable membre response ici
        QJsonDocument jsonDocument = QJsonDocument::fromJson(QByteArray(response.c_str()));

        if (!jsonDocument.isNull() && jsonDocument.isObject()) {
            QJsonObject jsonObject = jsonDocument.object();

            // Vérifiez s'il y a une erreur dans la réponse
            if (jsonObject.contains("cod") && jsonObject["cod"].isString()) {
                std::string cod = jsonObject["cod"].toString().toStdString();

                if (cod != "200") {
                    // Il y a une erreur, affichez le message d'erreur
                    std::cerr << "Erreur de l'API (code " << cod << "): " << jsonObject["message"].toString().toStdString() << std::endl;

                    // Affichez le message d'erreur dans le QLabel
                    ui->statusLabel->setText("VILLE NON TROUVÉE");
                    ui->statusLabel->setStyleSheet("QLabel { color: red; }");  // Texte en rouge
                    return;  // Sortez de la fonction en cas d'erreur
                }
            }

            // Pas d'erreur, affichez le statut "VALIDE"
            ui->statusLabel->setText("VALIDÉ");
            ui->statusLabel->setStyleSheet("QLabel { color: green; }");  // Texte en vert

            // Extraction des informations nécessaires du JSON
            double temperature = jsonObject["main"].toObject()["temp"].toDouble() - 273;
            QString description = jsonObject["weather"].toArray()[0].toObject()["description"].toString();
            double humidity = jsonObject["main"].toObject()["humidity"].toDouble();
            double windSpeed = jsonObject["wind"].toObject()["speed"].toDouble();

            // Mise à jour des QLabel dans le formulaire principal
            ui->temperatureLabel->setText("Température: " + QString::number(temperature) + " °C");
            ui->descriptionLabel->setText("Description: " + description);
            ui->humidityLabel->setText("Humidité: " + QString::number(humidity) + "%");
            ui->windSpeedLabel->setText("Vitesse du vent: " + QString::number(windSpeed) + " m/s");

            // Affichage d'autres informations
            double minTemperature = jsonObject["main"].toObject()["temp_min"].toDouble() - 273.15;
            double maxTemperature = jsonObject["main"].toObject()["temp_max"].toDouble() - 273.15;
            double pressure = jsonObject["main"].toObject()["pressure"].toDouble();
            QString sunrise = QDateTime::fromSecsSinceEpoch(jsonObject["sys"].toObject()["sunrise"].toInt()).toString("hh:mm:ss");
            QString sunset = QDateTime::fromSecsSinceEpoch(jsonObject["sys"].toObject()["sunset"].toInt()).toString("hh:mm:ss");

            ui->minTemperatureLabel->setText("Température minimale: " + QString::number(minTemperature) + " °C");
            ui->maxTemperatureLabel->setText("Température maximale: " + QString::number(maxTemperature) + " °C");
            ui->pressureLabel->setText("Pression: " + QString::number(pressure) + " hPa");
            ui->sunriseLabel->setText("Lever du soleil: " + sunrise);
            ui->sunsetLabel->setText("Coucher du soleil: " + sunset);

            // Mettez à jour les QLabel avec les valeurs actuelles du formulaire
            ui->countryLabel->setText("Pays : " + QString::fromStdString(pays));
            ui->cityLabel->setText("Ville : " + QString::fromStdString(ville));

            std::cerr << "Informations actualisées !" << std::endl;

        } else {
            std::cerr << "Erreur lors de l'analyse du JSON." << std::endl;
            std::cerr << response << std::endl;
        }

        // Effacez le contenu de la variable response après chaque mise à jour
        response.clear();
    }

private slots:
    void on_submitButton_clicked() {
        // Obtenez la ville et le pays à partir des zones de texte
        QString city = ui->cityLineEdit->text();
        QString country = ui->countryLineEdit->text();

        // Mettez à jour les variables globales avec les nouvelles valeurs
        ville = city.toStdString();
        pays = country.toStdString();

        // Effectuez une nouvelle demande avec les nouvelles valeurs
        fetchData();

        std::cout << "Nouvelle demande pour la ville : " << ville << ", pays : " << pays << std::endl;
    }

private:
    Ui::MainWindow* ui;
    QTimer* timer;  // Ajout du minuteur
    std::string currentCountry;  // Ajout de la variable pour stocker le pays actuel
    std::string currentCity;  // Ajout de la variable pour stocker la ville actuelle


    void fetchData() {
        // Construisez l'URL avec les valeurs actuelles des variables globales
        std::string url = "https://api.openweathermap.org/data/2.5/weather?q=" + ville + "," + pays + "&appid=" + api_key;

        CURL* curl;
        CURLcode res;

        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
            res = curl_easy_perform(curl);

            if (res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();

        // Traitez la réponse JSON ici (utilisez une bibliothèque comme nlohmann/json)
        std::cout << "Réponse de l'API : " << response << std::endl;

        // Mise à jour des informations après chaque nouvelle demande
        updateWeatherInformation();
    }
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MyMainWindow mainWindow;
    mainWindow.show();

    return a.exec();
}
