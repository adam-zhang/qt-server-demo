/********************************************************************************
> FileName:	MainWidget.cpp
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Wed Apr 21 06:52:33 2021
********************************************************************************/

#include "MainWidget.h"
#include "../shared/LocalSettings.h"
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QTcpSocket>

MainWidget::MainWidget(QWidget* parent)
	: QWidget(parent)

{
	initialize();
}

MainWidget::~MainWidget()
{
}

void MainWidget::initialize()
{
	makeWidget();
}

void MainWidget::makeWidget()
{
	auto layout = new QVBoxLayout(this);
	layout->addLayout(makeSendingWidgets());
	layout->addWidget(makeReceivedWigets());
}

QLayout* MainWidget::makeSendingWidgets()
{
	auto layout = new QHBoxLayout;
	layout->addWidget(makeSendingContent());
	layout->addWidget(makeSendingButton());
	return layout;
}

QWidget* MainWidget::makeSendingContent()
{
	auto edit = new QLineEdit;
	Q_ASSERT(edit);
	lineEdit_ = edit;
	return edit;
}

QWidget* MainWidget::makeReceivedWigets()
{
	receivedEdit_ = new QTextEdit;
	Q_ASSERT(receivedEdit_);
	return receivedEdit_;
}

QWidget* MainWidget::makeSendingButton()
{
	auto button = new QPushButton("&Send");
	Q_ASSERT(button);
	connect(button, &QPushButton::clicked, this, &MainWidget::onSendingButton);
	return button;
}

void MainWidget::onSendingButton()
{
	auto client = std::make_shared<QTcpSocket>();
	Q_ASSERT(client);
	connect(client.get(), &QTcpSocket::readyRead, this, &MainWidget::onReadRead);
	client->connectToHost(LocalSettings::serverAddress(), LocalSettings::port());
	client->write(lineEdit_->text().toLocal8Bit());
	tcpClient_ = client;
}

void MainWidget::onReadRead()
{
	auto text = QString("%1\n%2").arg(receivedEdit_->toPlainText()).arg(tcpClient_->readAll().data());
	receivedEdit_->setText(text);
}
