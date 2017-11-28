/*
 *  GHO-Äpp - App to view the Vertretungsplan conviniently
 *
 *  Copyright (C) 2017 JBBgameich <jbb.mail@gmx.de>
 *  Copyright (C) 2017 LNJ <git@lnj.li>
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

import QtQuick 2.6
import org.kde.kirigami 2.0 as Kirigami
import QtQuick.Controls 1.4 as Controls1
import QtQuick.Controls.Styles 1.4

Kirigami.Page {
	leftPadding: 0
	rightPadding: 0
	bottomPadding: 0
	topPadding: 0

	title: "Vertretungsplan"

	Controls1.TableView {
		anchors.fill: parent
		selectionMode: Controls1.SelectionMode.NoSelection

		Controls1.TableViewColumn {
			role: "lesson"
			title: "Stunde"
			width: 70
		}
		Controls1.TableViewColumn {
			role: "course"
			title: "Kurs"
			width: 100
		}
		Controls1.TableViewColumn {
			role: "subject"
			title: "Fach"
			width: 100
		}
		Controls1.TableViewColumn {
			role: "room"
			title: "Raum"
			width: 100
		}
		Controls1.TableViewColumn {
			role: "teacher"
			title: "VLehrer"
			width: 100
		}
		Controls1.TableViewColumn {
			role: "notes"
			title: "Info"
			width: 200
		}
		Controls1.TableViewColumn {
			role: "type"
			title: "Art"
			width: 200
		}

		model: ghoApp.vertPlanModel
	}
}
