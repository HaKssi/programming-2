#ifndef TEST_UI_1_H
#define TEST_UI_1_H

#include <QDialog>

namespace Ui {
class Test_UI_1;
}

class Test_UI_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Test_UI_1(QWidget *parent = nullptr);
    ~Test_UI_1();

private:
    Ui::Test_UI_1 *ui;
};

#endif // TEST_UI_1_H
