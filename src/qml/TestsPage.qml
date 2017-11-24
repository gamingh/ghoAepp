/*
 *  GHO-Äpp - App to view the Vertretungsplan conviniently
 *
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

import QtQuick 2.7
import org.kde.kirigami 2.0 as Kirigami
import QtQuick.Controls 2.0 as Controls

Kirigami.Page {
	title: "Entwickler Tests"

	Column {
		anchors.fill: parent
		spacing: 4

		Controls.Button {
			visible: true
			text: "Test Download"
			onClicked: ghoApp.downloadJson();
		}
	}
}
