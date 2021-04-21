/********************************************************************************
> FileName:	MainWidget.h
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Wed Apr 21 06:52:33 2021
********************************************************************************/
#ifndef __MAINWIDGET__H
#define __MAINWIDGET__H

#include <QWidget>
#include <memory>

class QLineEdit;
class QTextEdit;
class QTcpSocket;

class MainWidget : public QWidget
{
	Q_OBJECT
public:
	MainWidget(QWidget* parent = 0);
	~MainWidget();
private:
	void initialize();
	void makeWidget();
	QWidget* makeSendingButton();
	QLayout* makeSendingWidgets();
	QWidget* makeReceivedWigets();
	QWidget* makeSendingContent();
private:
	QLineEdit* lineEdit_ = 0;
	QTextEdit* receivedEdit_ = 0;
	std::shared_ptr<QTcpSocket> tcpClient_;
private slots:
	void onSendingButton();
	void onReadRead();
};
#endif//__MAINWIDGET__H
