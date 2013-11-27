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
#include "ui_mainwindow.h"
#include <QtCore/QCryptographicHash>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBoxWebsites->addItem("LinuxFr", "linuxfr");
    ui->comboBoxWebsites->addItem("GMail", "gmail");
    ui->comboBoxWebsites->addItem("Hotmail", "hotmail");
    ui->comboBoxWebsites->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonCompute_clicked()
{
    QCryptographicHash hash(QCryptographicHash::Sha1);
    hash.addData(ui->comboBoxWebsites->itemData(ui->comboBoxWebsites->currentIndex()).toByteArray());
    hash.addData(QVariant(ui->lineEditPassword->text()).toByteArray());
    if (ui->spinBoxCutChar->value() == 0) {
        ui->lineEditResult->setText(hash.result().toHex());
    } else {
        QString text = hash.result().toHex();
        text.truncate(ui->spinBoxCutChar->value());
        ui->lineEditResult->setText(text);
    }
}
