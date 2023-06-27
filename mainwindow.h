#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_save_button_clicked();

    void on_pen_button_clicked();

    void on_eraser_button_clicked();

    void on_history_button_clicked();

    void on_actionsave_triggered();

    void on_actiondocument_triggered();

    void on_actionpen_triggered();

    void on_actioneraser_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
