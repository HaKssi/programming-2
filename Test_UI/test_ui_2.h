#ifndef TEST_UI_2_H
#define TEST_UI_2_H

#include <QDialog>

namespace Ui {
class Test_UI_2;
}

class Test_UI_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Test_UI_2(QWidget *parent = nullptr);
    ~Test_UI_2();

private:
    Ui::Test_UI_2 *ui;
};

#endif // TEST_UI_2_H
