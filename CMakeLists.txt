##############################################################################
# CMake
##############################################################################

cmake_minimum_required(VERSION 2.8.12)
project(ros_qml_template LANGUAGES CXX)
set (Qt5InstallationDir ~/Libraries/Qt5.10/5.10.1/gcc_64)

##############################################################################
# Catkin
##############################################################################

find_package(catkin REQUIRED COMPONENTS roscpp message_generation)

include_directories(${catkin_INCLUDE_DIRS})

# Use this to define what the package will export (e.g. libs, headers).
# Since the default here is to produce only a binary, we don't worry about
# exporting anything.

add_message_files(
  FILES
  foo.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
  ros_qml_template
)

catkin_package(
    CATKIN_DEPENDS roscpp message_runtime
)

##############################################################################
# Qt Environment
##############################################################################

set (CMAKE_PREFIX_PATH ${Qt5InstallationDir}/)
set (Qt5Core_DIR ${Qt5InstallationDir}/lib/cmake/Qt5Core)
set (Qt5Gui_DIR ${Qt5InstallationDir}/lib/cmake/Qt5Gui)
set (Qt5Network_DIR ${Qt5InstallationDir}/lib/cmake/Qt5Network)
set (Qt5Qml_DIR ${Qt5InstallationDir}/lib/cmake/Qt5Qml)
set (Qt5Quick_DIR ${Qt5InstallationDir}/lib/cmake/Qt5Quick)
set (Qt5_DIR ${Qt5InstallationDir}/lib/cmake/Qt5_DIR)
set (Qt_DIR ${Qt5InstallationDir})

find_package(Qt5 COMPONENTS Core Gui Qml Quick REQUIRED)
#find_package(Qt5QuickCompiler)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Finding headers and launch files for QtCreator
file(GLOB_RECURSE HDRS ${CMAKE_CURRENT_SOURCE_DIR} *.h *.hpp)
file(GLOB_RECURSE SRCS ${CMAKE_CURRENT_SOURCE_DIR} *.cxx *.cpp *.c *.py)
file(GLOB_RECURSE LNCH ${CMAKE_CURRENT_SOURCE_DIR} *.launch)


##############################################################################
# Project includes
##############################################################################

include_directories (include)
include_directories (src)
include_directories (msg)
include_directories (launch)
include_directories (resources)


##############################################################################
# Sources
##############################################################################
set(QML2_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}" )
set(QML_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}" )
#set(QML2_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/resources/qmldir" )

message("QML import path is " ${QML_IMPORT_PATH})

##############################################################################
# Binaries
##############################################################################
qt5_add_resources(RESOURCES qml.qrc)
#qtquick_compiler_add_resources(RESOURCES qml.qrc)
#add_executable(ros_qml_template "main.cpp" "qml.qrc" )
add_executable(ros_qml_template "main.cpp" ${RESOURCES} )

qt5_use_modules(ros_qml_template Quick Core)

target_link_libraries(ros_qml_template Qt5::Core Qt5::Quick ${catkin_LIBRARIES})

target_include_directories(ros_qml_template PUBLIC include)
install(TARGETS ros_qml_template RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
