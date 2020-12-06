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
    currentHash.clear();
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

    for (auto it = current.begin(); it != current.end(); ++it) {
           if (it->getName() == ui->resDel->text().toStdString()) {
               it = current.erase(it);
           }
    }
    //current.pop(Restaurant(ui->resDel->text().toStdString()));

    /*for (Restaurant i: current) {
        current.erase(i); //remove(Restaurant(ui->resDel->text().toStdString()));
    }*/

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

        QFile fileIn("filein.txt");
        QFile fileOut("fileout.txt");
        if(fileIn.open(QIODevice::ReadOnly) && fileOut.open(QIODevice::WriteOnly))
        { //Если первый файл открыт для чтения, а второй для записи успешн
            QByteArray block = fileIn.read(10); // Считываем 10 байт в массив block из filein.txt
            fileOut.write(block); // Записываем 10 байт в файл fileout.txt
            fileIn.close(); // Закрываем filein.txt
            fileOut.close(); // Закрываем fileout.txt
        }
   /* currentHash.saveToFile("C:\\Qt\\a.txt");
    QFile f( ui->lineEdit_file_input_name->text() );
    f.open( QIODevice::WriteOnly | QIODevice::Text );

    QTextStream strm( &f );

    //Node<element*> *n = stackData.top_ptr;
    for (Restaurant i: current) {



    while (n != NULL)
    {
        strm << n->el->getType() << "\n";
        n->el->write( strm );

        n = n->next;
    }

    strm.flush();
    f.close();
    //currentHash.loadFromFile("f.txt");

    //QTextStream out(stdout);
    //QString filename = "f.txt";

    //QFile file(filename);

    /*ifstream file1("f.txt");

    if (file1.is_open())
    {

        for (Restaurant i: current) {

            out << "aaaa" << endl;

         }

        file1.close();
    }*/


    /*std::ofstream fs(filename);
    fs.write((char *) &m_size, sizeof(m_size) );

    for (Restaurant i: current) {
            int s;
            std::string ks = i.toString();
            s = ks.size();
            fs.write((char *) &(s), sizeof(int));
            fs.write((char *) ks.c_str(), ks.size());

        }
            fs.close();*/

    /*if(file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);



        for (Restaurant i: current) {

            out << i.getName() << endl;*/

           // и передаем ему адрес объекта fileOut
                   //writeStream << "Text, text, text."; // Посылаем строку в поток для записи
                  // fileOut.close(); // Закрываем файл

            //file << i.toString() << endl;

            //file << i;
            //file.write(i.toString());
           //file.write(i.toString());
            /*ui->listWidget->addItem("Restaurant: " +
                                QString::fromStdString( i.toString()));
        }

   }
    //file.close();
    QMessageBox::information(this, "Input data", "Successful input data from file");
    ui->lineEdit_file_input_name->clear();*/
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

}

void MainWindow::on_addToSet_clicked()
{
    currentHash.addCurrent(current);
}
