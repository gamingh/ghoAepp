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

#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QUrl>
#include <QQuickWindow>

#include "GHOApp.h"


int main(int argc, char *argv[])
{
	qDebug() << "GHO-Äpp rocks!";
	
	//
	// App
	//

	// create a qt app
	QGuiApplication app(argc, argv);

	// name, display name, description
	QGuiApplication::setApplicationName(APPLICATION_NAME);
	QGuiApplication::setApplicationDisplayName(APPLICATION_DISPLAY_NAME);
	QGuiApplication::setApplicationVersion(VERSION_STRING);

	// attributes
	QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);


	//
	// Back-end
	//

	GHOApp ghoApp;


	//
	// QML-GUI
	//

	if (qgetenv("QT_QUICK_CONTROLS_STYLE").isEmpty()) {
		qDebug() << "QT_QUICK_CONTROLS_STYLE not set, setting to Material";
		qputenv("QT_QUICK_CONTROLS_STYLE", "Material");
	}
	qputenv("QT_QUICK_CONTROLS_1_STYLE", "Flat");


	QQmlApplicationEngine engine;
	engine.rootContext()->setContextProperty("ghoApp", &ghoApp);

	engine.load(QUrl("qrc:/qml/main.qml"));
	QObject *topLevel = engine.rootObjects().value(0);
	QQuickWindow *window = qobject_cast<QQuickWindow*>(topLevel);
	window->show();

	// enter qt main loop
	return app.exec();
}
