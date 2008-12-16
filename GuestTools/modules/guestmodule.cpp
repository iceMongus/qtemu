/*
 * guestmodule.cpp
 *
 *  Created on: Dec 14, 2008
 *      Author: Ben
 */

#include "guestmodule.h"

GuestModule::GuestModule(QDataStream *stream, QObject *parent)
: QObject(parent)
, stream(stream)
{
    connect(this, SIGNAL(sendData(QString, QString, QVariant)), parent, SLOT(dataSender(QString, QString, QVariant)));
}

GuestModule::~GuestModule() {
}

QString GuestModule::moduleName()
{
	return module;
}

void GuestModule::setModuleName(QString name)
{
    module = name;
}

void GuestModule::receiveData(QString type, QVariant data)
{

}

void GuestModule::send(QString type, QVariant data)
{
	emit sendData(module, type, data);
}