# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Comet_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Comet_autogen.dir/ParseCache.txt"
  "Comet_autogen"
  )
endif()
