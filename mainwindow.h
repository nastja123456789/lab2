#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QMainWindow>
#include "HashMap.h"
#include "restaurant.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_size_clicked();

    void on_pushButton_add_ok_clicked();

    void on_pushButton_delete_all_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_file_input_ok_clicked();

    void on_pushButton_file_output_ok_clicked();

    void on_pushButton_add_ok_2_clicked();

    void on_addToSet_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
