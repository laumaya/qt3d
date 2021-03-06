/****************************************************************************
**
** Copyright (C) 2015 Klaralvdalens Datakonsult AB (KDAB).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QT3DINPUT_QACTION_H
#define QT3DINPUT_QACTION_H

#include <Qt3DInput/qt3dinput_global.h>
#include <Qt3DCore/qnode.h>

QT_BEGIN_NAMESPACE

namespace Qt3DInput {

class QActionPrivate;
class QAbstractActionInput;

class QT3DINPUTSHARED_EXPORT QAction : public Qt3DCore::QNode
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
public:
    explicit QAction(Qt3DCore::QNode *parent = Q_NULLPTR);
    ~QAction();

    QString name() const;


public Q_SLOTS:
    void setName(const QString &name);
    void addInput(QAbstractActionInput *input);
    void removeInput(QAbstractActionInput *input);
    QVector<QAbstractActionInput *> inputs() const;

Q_SIGNALS:
    void nameChanged(const QString &name);

    void started(const QString &name);
    void finished(const QString &name);

protected:
    void copy(const Qt3DCore::QNode *ref) Q_DECL_OVERRIDE;

private:
    Q_DECLARE_PRIVATE(QAction)
    QT3D_CLONEABLE(QAction)
};

} // Qt3DInput

QT_END_NAMESPACE

#endif // QT3DINPUT_QACTION_H
