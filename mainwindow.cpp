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
