#include "mainwindow.h"
#include "iostream"
#include <HashMap.h>
#include <QApplication>
#include <restaurant.h>


int main(int argc, char *argv[])
{
    /*HashSet<Restaurant> set1;
    assert(set1.size() == 0);
    set1.put(Restaurant("Restaurant"));
    assert(set1.size() == 1);
    assert(set1.contains(Restaurant("Restaurant")));
    set1.put("R2");
    assert(set1.size() == 2);

    HashSet set2 = HashSet(set1);
    assert(set1 == set2);
    set2.clear();
    assert(set2.size() == 0);

    set1.saveToFile("file1");
    auto set3 = HashSet<Restaurant>();
    set3.loadFromFile("file1");
    assert(set1 == set3);
    set1 << "R3" << "R4";
    assert(set1.contains("R3") && set1.contains("R4"));
    set1.remove("R3");
    assert(!set1.contains("R3"));
    assert(!set1["R3"] && set1["R4"]);
    set3 << "R5";
    auto set4 = set1 && set3;
    assert(set4.contains("Restaurant") && set4.contains("R2") && set4.size() == 2);


    printf("Well done");
    return 0;*/


  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
