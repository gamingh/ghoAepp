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

#include "VertPlanModel.h"
#include "VertPlanItem.h"

#include <QDebug>

VertPlanModel::VertPlanModel(QObject *parent) : QAbstractListModel(parent), list()
{
}

VertPlanModel::~VertPlanModel()
{
}

void VertPlanModel::addEntry(VertPlanItem* item)
{
	beginInsertRows(QModelIndex(), rowCount(), rowCount());
	list << item;
	endInsertRows();
}

QHash<int, QByteArray> VertPlanModel::roleNames() const
{
	QHash<int, QByteArray> roles;
	roles[LessonRole] = "lesson";
	roles[CourseRole] = "course";
	roles[SubjectRole] = "subject";
	roles[RoomRole] = "room";
	roles[TeacherRole] = "teacher";
	roles[NotesRole] = "notes";
	roles[TypeRole] = "type";
	return roles;
}

QVariant VertPlanModel::data(const QModelIndex &index, int role) const
{
	if (index.row() < 0 || index.row() >= list.count())
		return QVariant();

	const VertPlanItem* item = list[index.row()];
	switch (role) {
		case LessonRole: return item->getLesson();
		case CourseRole: return item->getCourse();
		case SubjectRole: return item->getSubject();
		case RoomRole: return item->getRoom();
		case TeacherRole: return item->getTeacher();
		case NotesRole: return item->getNotes();
		case TypeRole: return item->getType();
	}
	return QVariant();
}

int VertPlanModel::rowCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);
	return list.count();
}
