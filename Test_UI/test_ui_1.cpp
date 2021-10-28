#include "test_ui_1.h"
#include "ui_test_ui_1.h"

Test_UI_1::Test_UI_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Test_UI_1)
{
    ui->setupUi(this);
}

Test_UI_1::~Test_UI_1()
{
    delete ui;
}
