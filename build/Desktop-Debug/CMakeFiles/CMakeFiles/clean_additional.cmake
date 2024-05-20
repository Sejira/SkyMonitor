# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Sky_Monitor_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Sky_Monitor_autogen.dir/ParseCache.txt"
  "Sky_Monitor_autogen"
  )
endif()
