cmake_minimum_required(VERSION 3.1.0)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Network CONFIG REQUIRED)
set(sources main.cpp
	MainWindow.cpp
	MainWidget.cpp
	../shared/LocalSettings.cpp
	#TcpClient.cpp
	)
add_executable(client ${sources})
target_link_libraries(client Qt5::Widgets Qt5::Network)
