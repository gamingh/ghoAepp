/*
 *  GHO-Äpp - App to view the Vertretungsplan conviniently
 *
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

#ifndef VERTPLANMODEL_H
#define VERTPLANMODEL_H

#include <QAbstractListModel>

class VertPlanItem;
class QVariant;
class QByteArray;

class VertPlanModel : public QAbstractListModel
{
	Q_OBJECT
public:
	VertPlanModel(QObject *parent = 0);
	~VertPlanModel();
	void addEntry(VertPlanItem *item);
	QHash<int, QByteArray> roleNames() const;
	QVariant data(const QModelIndex &index, int role) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;

	enum VertPlanRoles {
		LessonRole = Qt::UserRole + 1,
		CourseRole,
		SubjectRole,
		RoomRole,
		TeacherRole,
		NotesRole,
		TypeRole
	};

private:
	QList<VertPlanItem*> list;
};

#endif // VERTPLANMODEL_H
