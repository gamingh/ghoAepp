/*
 *  GHO-Äpp - App to view the Vertretungsplan conviniently
 *
 *  Copyright (C) 2017 LNJ <git@lnj.li>
 *  Copyright (C) 2017 JBBgameich <jbb.mail@gmx.de>
 *
 *  GHO-Äpp is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  GHO-Äpp is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GHO-Äpp. If not, see <http://www.gnu.org/licenses/>.
 */

#include "GHOApp.h"
#include "VertPlanItem.h"
#include "VertPlanModel.h"

#include <QDebug>
#include <QUrl>
#include <QUrlQuery>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QAuthenticator>
#include <QSettings>

static const QString JSON_DATA_HTTP_URL("http://gamerbudebb.d.pboehm.de/gho/"
					 "vertretungsplan.json");
static const QString JSON_DATA_HTTP_USERNAME("ghoschueler");

GHOApp::GHOApp(QObject *parent) : QObject(parent)
{
	// load settings (<= ~/.config/ghoaepp/ghoaepp.conf)
	QSettings settings(APPLICATION_NAME, APPLICATION_NAME);
	password = settings.value("auth/password").toString();

	vertPlanModel = new VertPlanModel(this);
	// FIXME: Remove and parse from JSON
	vertPlanModel->addEntry(new VertPlanItem(
		8, QString("10.24"), QString("Ku"), QString("F63"),
		QString(""), QString(""), QString("Fällt aus")
	));
	vertPlanModel->addEntry(new VertPlanItem(
		4, QString("07.13"), QString("Ge"), QString("B08"),
		QString("Nowi"), QString(""), QString("")
	));
	vertPlanModel->addEntry(new VertPlanItem(
		1, QString("09.1 Ma 0F01"), QString("Ma"), QString("B31"),
		QString("MülD"), QString("Arbeitsauftrag"), QString("")
	));
	vertPlanModel->addEntry(new VertPlanItem(
		1, QString("11.1"), QString("Ph"), QString("E08"),
		QString(""), QString("Arbeitsauftrag"), QString("Fällt aus")
	));

	emit vertPlanModelChanged();
}

GHOApp::~GHOApp()
{
}

void GHOApp::downloadJson()
{
	QNetworkAccessManager *manager = new QNetworkAccessManager(this);

	// when the manager finishes downloading, trigger `handleJsonData`
	connect(manager, SIGNAL(finished(QNetworkReply*)),
		this, SLOT(handleJsonData(QNetworkReply*)));
	// when the manager requires authentication, trigger `handleAuthenticationRequired`
	connect(manager, SIGNAL(authenticationRequired(QNetworkReply*, QAuthenticator*)),
		this, SLOT(handleAuthenticationRequired(QNetworkReply*, QAuthenticator*)));

	// manager will automatically trigger `handleJsonData`, when finished
	manager->get(QNetworkRequest(QUrl(JSON_DATA_HTTP_URL)));
}

void GHOApp::handleAuthenticationRequired(QNetworkReply *reply,
	QAuthenticator *authenticator)
{
	qDebug() << "Hello there!";
	authenticator->setUser(JSON_DATA_HTTP_USERNAME);
	if (!password.isEmpty())
		authenticator->setPassword(password);
	else
		qWarning() << "Warning: Et wurde keen Passwort jesetzt!";
}

void GHOApp::handleJsonData(QNetworkReply *reply)
{
	if (reply->error()) {
		qDebug() << "Error: Et jibt 1 Problehm beem einwaehln:" << reply->errorString();
		return;
	} else {
		qDebug() << "Yo, geil et jeht";
		qDebug() << "Groesse der JSON Datei:" << reply->readAll().length() << "bytes";
	}
}

VertPlanModel* GHOApp::getVertPlanModel()
{
	return vertPlanModel;
}
