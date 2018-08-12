cmake_minimum_required(VERSION 3.12)
project(FlauschArchivar)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_BUILD_TYPE DEBUG)

set(ARCHIV_SRC main.cpp databaseaccess.cpp databaseaccess.h flauscharchivar_global.h)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Sql CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Gui CONFIG REQUIRED)

get_target_property(QtCore_location Qt5::Core LOCATION)
get_target_property(QtSql_location Qt5::Sql LOCATION)
get_target_property(QtWidgets_location Qt5::Widgets LOCATION)
get_target_property(QtGui_location Qt5::Gui LOCATION)

set(CMAKE_CXX_STANDARD 11)

add_executable(FlauschArchivar ${ARCHIV_SRC} resource_file.qrc)

set(CMAKE_EXE_LINKER_FLAGS " -static")

target_link_libraries(FlauschArchivar Qt5::Core)
target_link_libraries(FlauschArchivar Qt5::Sql)
target_link_libraries(FlauschArchivar Qt5::Widgets)
target_link_libraries(FlauschArchivar Qt5::Gui)
target_link_libraries(FlauschArchivar -static-libgcc -static-libstdc++)

install(TARGETS FlauschArchivar RUNTIME DESTINATION bin)