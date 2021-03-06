/*
  plugininfo.h

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2014-2015 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Volker Krause <volker.krause@kdab.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GAMMARAY_PLUGININFO_H
#define GAMMARAY_PLUGININFO_H

#include <QString>
#include <QStringList>

namespace GammaRay {

/** Meta-data about a specific plugin.
 *  This abstracts Qt5-style embedded JSON data and Qt4-style desktop files.
 */
class PluginInfo
{
public:
    PluginInfo();
    explicit PluginInfo(const QString &path);

    QString path() const;
    QString id() const;
    QString interface() const;
    QStringList supportedTypes() const;
    QString name() const;
    bool remoteSupport() const;
    bool isHidden() const;

    bool isValid() const;

private:
    void initFromJSON(const QString &path);
    void initFromDesktopFile(const QString &path);

    QString m_path;
    QString m_id;
    QString m_interface;
    QStringList m_supportedTypes;
    QString m_name;
    bool m_remoteSupport;
    bool m_hidden;
};
}

#endif // GAMMARAY_PLUGININFO_H
