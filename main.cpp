#include "mainwindow.h"
#include "iostream"
#include "hashtable.h"
#include "test.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    std::setlocale(LC_ALL,"RUS");
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));

    HashTableTest<std::string> test ;
    test.StartHashTableTests();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
