/******************************************************************************
**
** Copyright (C) 2003-2012 DIATEAM. All rights reserved.
**
** This file is part of Hynesim.
**
** Hynesim is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License version 2 
** as published by the Free Software Foundation.
**
** Hynesim is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
******************************************************************************/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
