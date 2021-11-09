#ifndef SECDIALOG2_H
#define SECDIALOG2_H

#include <QDialog>

namespace Ui {
class SecDialog2;
}

class SecDialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog2(QWidget *parent = nullptr);
    ~SecDialog2();

private slots:
    void on_home_clicked();

    void on_course_clicked();

    void on_course_plus_clicked();

    void on_stu_clicked();

    void on_student_plus_clicked();

private:
    Ui::SecDialog2 *ui;
};

#endif // SECDIALOG2_H
