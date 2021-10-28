#include "test_ui_2.h"
#include "ui_test_ui_2.h"

Test_UI_2::Test_UI_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Test_UI_2)
{
    ui->setupUi(this);
}

Test_UI_2::~Test_UI_2()
{
    delete ui;
}
