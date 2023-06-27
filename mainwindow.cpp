#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFocusEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Notepad_v1");
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_save_button_clicked()
{
    QString text = ui->text_content->toPlainText();
//    qDebug() << text;
    QFile file("D:\\Documents\\qt project\\notepad_v1\\data.txt");
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)){
//        qDebug() << text << "\n";
        return ;
    }else{
        file.close();
    }
    QTextStream out(&file);
    out << text << "\n";

    ui->text_content->setReadOnly(true);
}


void MainWindow::on_pen_button_clicked()
{
    ui->text_content->setReadOnly(false);
    if(!ui->text_content->isReadOnly()){
        QTextCursor cursor = ui->text_content->textCursor();
//        cursor.insertText("hhhh");
        cursor.movePosition(QTextCursor::End);
        ui->text_content->setFocus();
        ui->text_content->ensureCursorVisible();
    }
}


void MainWindow::on_eraser_button_clicked()
{
    if(!ui->text_content->isReadOnly()){
        ui->text_content->setText("");
        ui->text_content->setFocus();
        ui->text_content->ensureCursorVisible();
    }
}


void MainWindow::on_history_button_clicked()
{
    if(!ui->text_content->isReadOnly()){
        QFile file("D:\\Documents\\qt project\\notepad_v1\\data.txt");
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream in(&file);
            QString text = in.readAll();
            ui->text_content->setPlainText(text);
            file.close();
        }
        ui->text_content->setFocus();
    }
}

void MainWindow::on_actionsave_triggered()
{
    on_save_button_clicked();
}

void MainWindow::on_actiondocument_triggered(){
    on_history_button_clicked();
}

void MainWindow::on_actionpen_triggered(){
    on_pen_button_clicked();
}

void MainWindow::on_actioneraser_triggered(){
    on_eraser_button_clicked();
}
