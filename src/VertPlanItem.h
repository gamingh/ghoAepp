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

#ifndef VERTPLANITEM_H
#define VERTPLANITEM_H

#include <QObject>
#include <QString>

class VertPlanItem : public QObject
{
	Q_OBJECT
	Q_PROPERTY(unsigned int lesson READ getLesson)
	Q_PROPERTY(QString course READ getCourse)
	Q_PROPERTY(QString subject READ getSubject)
	Q_PROPERTY(QString room READ getRoom)
	Q_PROPERTY(QString teacher READ getTeacher)
	Q_PROPERTY(QString notes READ getNotes)
	Q_PROPERTY(QString type READ getType)

public:
	VertPlanItem(QObject *parent = 0);
	VertPlanItem(unsigned int lesson, QString course, QString subject, QString room, QString teacher, QString notes, QString type, QObject *parent = 0);
	~VertPlanItem();
	
	unsigned int getLesson() const
	{
		return lesson;
	}
	void setLesson(unsigned int lesson)
	{
		this->lesson = lesson;
	}

	QString getCourse() const
	{
		return course;
	}
	void setCourse(QString course)
	{
		this->course = course;
	}

	QString getSubject() const
	{
		return subject;
	}
	void setSubject(QString subject)
	{
		this->subject = subject;
	}

	QString getRoom() const
	{
		return room;
	}
	void setRoom(QString room)
	{
		this->room = room;
	}

	QString getTeacher() const
	{
		return teacher;
	}
	void setTeacher(QString teacher)
	{
		this->teacher = teacher;
	}

	QString getNotes() const
	{
		return notes;
	}
	void setNotes(QString notes)
	{
		this->notes = notes;
	}

	QString getType() const
	{
		return type;
	}
	void setType(QString type)
	{
		this->type = type;
	}

private:
	unsigned int lesson;
	QString course;
	QString subject;
	QString room;
	QString teacher;
	QString notes;
	QString type;
};

#endif // VERTPLANITEM_H
