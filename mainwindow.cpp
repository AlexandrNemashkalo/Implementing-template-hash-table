#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdynamicauthor.h"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QScrollArea"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget* ScrollAreaWidgetContents = new QWidget();
    ui->scrollArea->setWidget(ScrollAreaWidgetContents);
    scrollLayout = new QHBoxLayout(ScrollAreaWidgetContents);


    Author *a = new Author("Иван Иванов");

    AddAuthor(a);

}

MainWindow::~MainWindow()
{

    delete ui;

}


void MainWindow::AddAuthor(Author * author){
    authors.push_back(author);
    scrollLayout->addWidget(new QDynamicAuthor(this,author));
}



void MainWindow::on_pushButton_clicked()
{
    if(ui->downloadFile->text() !=""){

        HashTable<std::string> ht;
        if(!ht.GetHashTableFromFile(ui->downloadFile->text().toStdString()))
        {
             QMessageBox::information( this, "Button was clicked!",QString("не удалось найти файл"));
        }
        else {
            Author * a  = new Author(ui->lineEdit->text().toStdString(),&ht);
            AddAuthor(a);
        }
    }
    else{
        AddAuthor(new Author(ui->lineEdit->text().toStdString()));
    }
}




void MainWindow::on_loadFileBtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Открыть файл"),
                                QDir::currentPath(),
                                "TXT File(*.txt)");

    if(!(fileName =="")){
        ui->downloadFile->setText(fileName);
    }


}

void MainWindow::on_pushButton_3_clicked()
{
    ui->downloadFile->setText("");
}

void MainWindow::on_createCollectionBtn_clicked()
{
    HashTable<std::string>* result = authors[0]->genres;
    ui->listWidget->clear();
    for(int i =1;i<authors.size();i++){
        result = *result && *(authors[i]->genres);
    }
    if(result->GetSize()>0){
        for (int i = 0; i < result->GetBufferSize(); ++i){
                std::string  value =  result->GetValueByKey(i);
                if(value != std::string())
                    ui->listWidget->addItem(QString::fromStdString(value));
        }
    }
    else
         QMessageBox::information( this, "Button was clicked!",QString("Сборник пуст"));
}
