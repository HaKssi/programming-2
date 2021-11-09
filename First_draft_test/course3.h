#ifndef COURSE3_H
#define COURSE3_H

#include <QDialog>

namespace Ui {
class course3;
}

class course3 : public QDialog
{
    Q_OBJECT

public:
    explicit course3(QWidget *parent = nullptr);
    ~course3();

private slots:
    void on_back_pushbutton_clicked();

    void on_course_clicked();

    void on_stu_clicked();

    void on_home_clicked();

    void on_cousrse_plus_clicked();

    void on_home_2_clicked();

    void on_student_plus_clicked();

private:
    Ui::course3 *ui;
};

#endif // COURSE3_H
