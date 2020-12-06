#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "HashMap.h"
#include <string.h>
#include <stdlib.h>
#include <QTextStream>
#include <QFile>
#include "restaurant.h"
#include <fstream>
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::vector<Restaurant> current;
HashSet<Restaurant> currentHash;

void MainWindow::on_pushButton_delete_all_clicked()
{
    current.clear();
    ui->listWidget->clear();
}

void MainWindow::on_pushButton_size_clicked()
{
    QMessageBox::information(this, "Size", "The size of list is " + QString::number(currentHash.size()));
}

void MainWindow::on_pushButton_add_ok_clicked()
{
    auto rest = Restaurant(ui->lineEdit_add_2->text().toStdString());

    for (auto it = current.begin(); it != current.end(); ++it) {
           if (it->getName() == rest.getName()) {

               QMessageBox::information(this, "This","restaurant have been");

              return;
           }
    }

    current.push_back(rest);

    ui->listWidget->addItem("Restaurant: " + ui->lineEdit_add_2->text());
}

void MainWindow::on_pushButton_delete_clicked()
{

    ui->listWidget->clear();

    remove(current.begin(), current.end(), Restaurant(ui->resDel->text().toStdString()));

    current.pop_back();


    for (Restaurant i: current) {
        ui->listWidget->addItem("Restaurant: " +
                            QString::fromStdString( i.toString()));
    }

    //currentHash.removeLast();

    /*for ( Restaurant n:currentHash.)
         ui->listWidget->addItem("Restaurant: " + QString::fromStdString( n.toString()));*/
}


void MainWindow::on_pushButton_file_input_ok_clicked()
{


}


void MainWindow::on_pushButton_file_output_ok_clicked()
{
    string filename = ui->lineEdit_file_output_name->text().toStdString();
    if(filename.size())
        currentHash.loadFromFile(filename);
    QMessageBox::information(this, "Output data", "Successful output data to file");
    ui->lineEdit_file_output_name->clear();
}

void MainWindow::on_pushButton_add_ok_2_clicked()
{
    current = currentHash.round();

     ui->listWidget->clear();

     for (Restaurant i: current) {
         ui->listWidget->addItem("Restaurant: " +
                             QString::fromStdString( i.toString()));
     }
}

void MainWindow::on_addToSet_clicked()
{
    currentHash.addCurrent(current);

    current.clear();

     ui->listWidget->clear();
}

void MainWindow::on_pushButton_file_input_ok_2_clicked()
{

   QFile fileOut("C:\\Qt\\l\\HashSet\\fileout.txt"); // Связываем объект с файлом fileout.txt
       if(fileOut.open(QIODevice::Append | QIODevice::Text))
       { // Если файл успешно открыт для записи в текстовом режиме
          // QMessageBox::information(this, "Thi1s","restaurant have been");
           QTextStream writeStream(&fileOut);

           for (Restaurant i: current) {

               std::string str = i.getName();
               const char* p = str.c_str();

               writeStream << p << "\n";
           }

           writeStream << "\n";

           fileOut.close();
       }
       /*
        * string name = ui->lineEdit_file_input_name->text().toStdString();
    if(name.size())
    {
        this->collection.clear();
        this->collection.input_from_file(name);
        for(auto &i: this->collection.get())
            for(auto &j: i)
                ui->listWidget->addItem("Word: " +
                                    QString::fromStdString(j.first) +
                                    "\nCount: " +
                                    QString::number(j.second));
    }
    QMessageBox::information(this, "Input data", "Successful input data from file");
    ui->lineEdit_file_input_name->clear();
        */
}
