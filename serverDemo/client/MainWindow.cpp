#include "MainWindow.h"
#include "MainWidget.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	initialize();
};

MainWindow::~MainWindow()
{
}

void MainWindow::initialize()
{
	setCentralWidget(new MainWidget);
}
