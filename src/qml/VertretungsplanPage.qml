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
import QtQuick.Controls 1.4 as ControlsOne
import QtQuick.Controls.Styles 1.4

Kirigami.Page {
	leftPadding: 0
	rightPadding: 0
	bottomPadding: 0
	topPadding: 0

	title: "Vertretungsplan"

	ControlsOne.TableView {
		selectionMode: SelectionMode.NoSelection

		ControlsOne.TableViewColumn {
			role: "lesson"
			title: "Stunde"
			width: 100
		}
		ControlsOne.TableViewColumn {
			role: "group"
			title: "Gruppe"
			width: 200
		}

		anchors.fill: parent

		model: ListModel {
			ListElement {
				lesson: "1"
				group: "10.21"
			}
			ListElement {
				lesson: "5"
				group: "10.23"
			}
			ListElement {
				lesson: "9"
				group: "Ev. Religion 10"
			}
		}
	}
}
