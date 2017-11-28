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

#include "VertPlanItem.h"

VertPlanItem::VertPlanItem(QObject *parent) : QObject(parent)
{
}

VertPlanItem::VertPlanItem::VertPlanItem(unsigned int lesson, QString course,
	QString subject, QString room, QString teacher, QString notes,
	QString type, QObject *parent) : QObject(parent), lesson(lesson), course(course),
	subject(subject), room(room), teacher(teacher), notes(notes), type(type)
{
}

VertPlanItem::~VertPlanItem()
{
}
