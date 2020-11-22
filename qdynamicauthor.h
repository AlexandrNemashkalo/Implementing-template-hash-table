#ifndef QDYNAMICAUTHOR_H
#define QDYNAMICAUTHOR_H

#include <QFrame>
#include <author.h>
#include "QListWidget"
#include <QFileDialog>


class QDynamicAuthor : public QFrame
{
    Q_OBJECT

public:
    ~QDynamicAuthor();
    QDynamicAuthor(QWidget *parent =0,Author* author = 0);
    Author* author;
    void AddGenre(const std::string& value);


private:
    QListWidget * lstWgt ; //вот так нахуй!



public slots:
    void onBtnClicked() ;
    void onDeleteAuthorBtnClicked();
    void onPushBtnClicked();
    void onDeleteGanreBtnClicked();
    void showDeleteBtn(QListWidgetItem *current, QListWidgetItem *previous);
    void onDownloadAuthorBtnClicked();


};

#endif // QDYNAMICAUTHOR_H



