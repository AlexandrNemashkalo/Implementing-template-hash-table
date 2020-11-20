#include "mainwindow.h"
#include "iostream"
#include "hashtable.h"
#include "test.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();





    HashTableTest<std::string> test ;
    test.StartHashTableTests();

    //return 0;
    return a.exec();
}
