/****************************************************************************
**
** Copyright (C) 2014 Klaralvdalens Datakonsult AB (KDAB).
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

#ifndef QT3DRENDER_TEXTUREDATA_P_H
#define QT3DRENDER_TEXTUREDATA_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of other Qt classes.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "qtexturedata.h"

QT_BEGIN_NAMESPACE

namespace Qt3DRender {

class QTexImageDataPrivate
{
public:
    QTexImageDataPrivate();

    void setData(const QByteArray &data, QOpenGLTexture::PixelFormat fmt,
                 QOpenGLTexture::PixelType ptype);

    bool setCompressedFile(const QString &source);

    QByteArray data(int layer, int face, int mipmapLevel) const;

    int m_width;
    int m_height;
    int m_depth;
    int m_layers;
    int m_faces;
    int m_mipLevels;
    int m_blockSize;

    QOpenGLTexture::Target m_target;
    QOpenGLTexture::TextureFormat m_format;
    QOpenGLTexture::PixelFormat m_pixelFormat;
    QOpenGLTexture::PixelType m_pixelType;

    bool m_isCompressed;
    QByteArray m_data;

private:
    int layerSize() const;
    int faceSize() const;
    int mipmapLevelSize(int level) const;

    bool setPkmFile(const QString &source);
    bool setDdsFile(const QString &source);
};

} // namespace Qt3DRender


QT_END_NAMESPACE

#endif // QT3DRENDER_TEXTUREDATA_P_H
