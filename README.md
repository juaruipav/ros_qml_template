# ros_qml_template

The goal of this repository is to create a Qt/QML application as a ROS package and mix both programming structure in a single project.

## Features

The basic structure of the repository is:


```
ros_qml_template
|
|---> include	// Headers
|---> src	// Your C++/ROS code
|---> launch	// Launch files from ROS
|---> msg	// Custom messages from ROS
|---> resources	// Qt/QML resources (image/multimedia)
|---> qml	// QML resources (.qml files)
|---> main.cpp	// C++ main file
|---> main.qml	// QML main file

```

## Pre-requisites

Just simple as editing the CMakeFile and replace the Qt5.XX installation dir path with your own path
```
set (Qt5InstallationDir ~/Libraries/Qt5.10/5.10.1/gcc_64)
```

## Compile and launch

Just clone the repository in your catkin workspace and compile as usual

```
$ catkin_make
$ roslaunch ros_qml_template ros_qml_template.launch
```











