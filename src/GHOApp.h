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

#ifndef GHOAPP_H
#define GHOAPP_H

#include <QObject>
#include <QQmlListProperty>

class QNetworkReply;
class QAuthenticator;
class VertPlanModel;

class GHOApp : public QObject
{
	Q_OBJECT
	Q_PROPERTY(VertPlanModel *vertPlanModel READ getVertPlanModel NOTIFY vertPlanModelChanged)

public:
	GHOApp(QObject* parent = 0);
	~GHOApp();

	Q_INVOKABLE void downloadJson();
	VertPlanModel* getVertPlanModel();

signals:
	void vertPlanModelChanged();

private slots:
	void handleAuthenticationRequired(QNetworkReply *reply,
		QAuthenticator *authenticator);
	void handleJsonData(QNetworkReply *reply);

private:
	QNetworkReply *reply;
	QString password;
	VertPlanModel *vertPlanModel;
};

#endif // GHOAPP_H
