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

#ifndef KNIGHTS_RENDERER_H
#define KNIGHTS_RENDERER_H

#include "kdeversion.h"
#if defined WITH_KGR
#include <KGameRenderer>
#define RendererBaseType KGameRenderer
#else
#include <QtSvg/QSvgRenderer>
#define RendererBaseType QSvgRenderer
#endif

class KGameTheme;

namespace Knights
{
    class Renderer : public RendererBaseType
    {
            Q_OBJECT
        public:
            Renderer ( const QString& defaultTheme );
            virtual ~Renderer();

#if not defined WITH_KGR
            bool spriteExists ( const QString& key );
            QRectF boundsOnSprite ( const QString& key );

        public Q_SLOTS:
            void setTheme ( const QString& theme );
        private:
            KGameTheme* m_theme;
#endif

    };
}

#endif // KNIGHTS_RENDERER_H
// kate: indent-mode cstyle; space-indent on; indent-width 4; replace-tabs on; 
