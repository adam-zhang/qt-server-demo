/********************************************************************************
> FileName:	LocalSettings.h
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Wed Apr 21 07:26:20 2021
********************************************************************************/
#ifndef __LOCALSETTINGS__H
#define __LOCALSETTINGS__H

#include <QString>

class LocalSettings
{
private:
	LocalSettings();
	~LocalSettings();
public:
	static QString serverAddress()
	{ return "127.0.0.1"; }
	static short port()
	{ return 12345; }
};
#endif//__LOCALSETTINGS__H
