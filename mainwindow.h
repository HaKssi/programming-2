#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QDialog>

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
    void on_course_clicked();

    void on_course_plus_clicked();

    void on_stu_clicked();

    void on_student_plus_clicked();

    void on_home_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_search_pushbutton_clicked();

    void on_Save_button_clicked();

    void on_Add_Pushbutton_clicked();

    void on_Add_Pushbutton_2_clicked();

    void on_search_pushbutton_2_clicked();

    void on_Save_button_2_clicked();

    void on_detail_Pushbutton_clicked();

    void on_detail_Pushbutton_2_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
    QSqlDatabase mydb2;
    QSqlDatabase mydb3;
    QSqlDatabase mydb_cou;
    QSqlDatabase mydb_stu;

    QSqlTableModel *model;
    QSqlTableModel *model2;
    QSqlTableModel *tbl_cou;
    QSqlTableModel *tbl_stu;
};
#endif // MAINWINDOW_H
