/*
 *  Kaidan - A user-friendly XMPP client for every device!
 * 
 *  Copyright (C) 2017 LNJ <git@lnj.li>
 *  Copyright (C) 2017 JBBgameich <jbb.mail@gmx.de>
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

#ifndef GHOAPP_H
#define GHOAPP_H

#include <QObject>

class QNetworkReply;
class QAuthenticator;

class GHOApp : public QObject
{
	Q_OBJECT

public:
	GHOApp(QObject *parent = 0);
	~GHOApp();

	Q_INVOKABLE void downloadJson();

protected slots:
	void handleAuthenticationRequired(QNetworkReply *reply,
		QAuthenticator *authenticator);
	void handleJsonData(QNetworkReply *reply);

private:
	QNetworkReply *reply;
	QString password;
};

#endif // GHOAPP_H
