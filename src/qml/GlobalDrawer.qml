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

import org.kde.kirigami 2.0 as Kirigami

Kirigami.GlobalDrawer {
	id: globalDrawer
	title: "GHO App"
	bannerImageSource: ""
	// make drawer floating (overlay)
	modal: true
	// start with closed drawer
	drawerOpen: false
	// show open button on the left side
	handleVisible: true

	actions: [
		Kirigami.Action {
			text: qsTr("Vertretungsplan")
			iconName: "korganizer"
			onTriggered: {
				pageStack.replace(vertretungsplanPage);
			}
		},
		Kirigami.Action {
			text: qsTr("Entwickler Tests")
			iconName: "dialog-warning"
			onTriggered: {
				pageStack.replace(testsPage);
			}
		}
	]
}
