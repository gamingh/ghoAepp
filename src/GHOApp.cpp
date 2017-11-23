/*
 *  Kaidan - A user-friendly XMPP client for every device!
 * 
 *  Copyright (C) 2017 LNJ <git@lnj.li>
 * 
 *  Kaidan is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 * 
 *  Kaidan is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 * 
 *  You should have received a copy of the GNU General Public License
 *  along with Kaidan. If not, see <http://www.gnu.org/licenses/>.
 */

#include "GHOApp.h"

#include <QDebug>
#include <QUrl>
#include <QUrlQuery>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>

#include <iostream>

static const QString CELLS_DATA_URL("http://gamerbudebb.d.pboehm.de/gho/vertretungsplan-cells.json");

GHOApp::GHOApp(QObject *parent) : QObject(parent)
{
}

GHOApp::~GHOApp()
{
}

void GHOApp::downloadJson()
{
	QNetworkAccessManager *manager = new QNetworkAccessManager();
	QUrl url(CELLS_DATA_URL);
	QUrlQuery query;

	query.addQueryItem("username", "ghoschueler");
	query.addQueryItem("password", ""); // I won't paste the password here :P

	url.setQuery(query.query());

	QNetworkRequest request(url);
	QNetworkReply *reply = manager->get(request);
	
	connect(reply, SIGNAL(readyRead()), this, SLOT(handleJsonData));
}

void GHOApp::handleJsonData()
{
	qDebug() << "Hello there!";
}
