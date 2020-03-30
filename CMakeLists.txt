cmake_minimum_required(VERSION "3.17")
project( "VSSS-Server" VERSION "1.0" )

find_package( OpenCV REQUIRED )
find_package(PkgConfig REQUIRED) 

pkg_check_modules(OpenCV REQUIRED IMPORTED_TARGET opencv4)

add_executable( "${PROJECT_NAME}" "src/main.cpp" )

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
install(FILES "src/main.cpp" DESTINATION src)
target_link_libraries( "${PROJECT_NAME}" ${OpenCV_LIBS} )
