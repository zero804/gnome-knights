/*
    This file is part of Knights, a chess board for KDE SC 4.
    Copyright 2009-2010  Miha Čančula <miha.cancula@gmail.com>

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 2 of
    the License or (at your option) version 3 or any later version
    accepted by the membership of KDE e.V. (or its successor approved
    by the membership of KDE e.V.), which shall act as a proxy
    defined in Section 14 of version 3 of the license.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef KNIGHTS_CLOCKWIDGET_H
#define KNIGHTS_CLOCKWIDGET_H

#include "core/piece.h"

#include <QtGui/QWidget>

class QGroupBox;
class QTimer;
class QTime;

namespace Ui
{
    class ClockWidget;
}

namespace Knights
{
    class ClockWidget : public QWidget
    {
            Q_OBJECT
        public:
            explicit ClockWidget ( QWidget* parent = 0, Qt::WindowFlags f = 0 );
            ~ClockWidget ();

        public Q_SLOTS:
            void setTimeLimit ( Color color, const QTime& time );
            void setTimeIncrement ( Color color, int seconds );
            void incrementTime ( Color color, int miliseconds );
            void setActivePlayer ( Color color );
            void setDisplayedPlayer ( Color color );
            void setPlayerName ( Color color, const QString& name );
            void setCurrentTime ( Color color, const QTime& time );

            void pauseClock();
            void resumeClock();

        Q_SIGNALS:
            void timeOut ( Color );
            void opponentTimeOut ( Color );

        protected:
            virtual void timerEvent ( QTimerEvent* );

        private:
            Ui::ClockWidget* ui;
            QMap<Color, QTimer> m_timer;
            QMap<Color, int> m_timerId;
            Color m_activePlayer;
            QMap<Color, QTime> m_timeLimit;
            QMap<Color, QTime> m_currentTime;
            QMap<Color, QGroupBox*> m_box;
            QMap<Color, int> m_timeIncrement;
            QMap<Color, bool> m_started;
    };
}

#endif // KNIGHTS_CLOCKWIDGET_H
// kate: indent-mode cstyle; space-indent on; indent-width 4; replace-tabs on;  replace-tabs on;
