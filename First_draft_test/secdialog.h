#ifndef SECDIALOG_H
#define SECDIALOG_H
#include <QtSql>
#include <QDialog>
#include "pro2.h"

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT



public:
    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();

private slots:


    void on_Add_Pushbutton_clicked();

    void on_loadData_clicked();

    void on_back_pushbutton_clicked();

    void on_course_clicked();

    void on_home_clicked();

    void on_stu_clicked();

    void on_course_plus_clicked();

    void on_home_2_clicked();

    void on_student_plus_clicked();

private:
    Ui::SecDialog *ui;
    QSqlDatabase mydb;
    QSqlTableModel *model;
    //QMainWindow *pro2;
};

#endif // SECDIALOG_H
