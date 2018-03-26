/*
    Copyright 2018, Mitch Curtis

    This file is part of Slate.

    Slate is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Slate is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Slate. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef APPLYLAYEREDIMAGEPIXELFILLCOMMAND_H
#define APPLYLAYEREDIMAGEPIXELFILLCOMMAND_H

#include <QDebug>
#include <QImage>
#include <QtUndo/undocommand.h>

class LayeredImageProject;

class ApplyLayeredImagePixelFillCommand : public UndoCommand
{
    Q_OBJECT

public:
    ApplyLayeredImagePixelFillCommand(LayeredImageProject *project, const QImage &previousImage,
        const QImage &newImage, UndoCommand *parent = nullptr);

    void undo() override;
    void redo() override;

    int id() const override;

private:
    friend QDebug operator<<(QDebug debug, const ApplyLayeredImagePixelFillCommand *command);

    LayeredImageProject *mProject;
    int mLayerIndex;
    QImage mPreviousImage;
    QImage mNewImage;
};

#endif // APPLYLAYEREDIMAGEPIXELFILLCOMMAND_H
