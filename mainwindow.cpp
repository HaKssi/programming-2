#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtSql>
#include <QPixmap>
#include <QDialog>
#include <string>
#include <QMessageBox>

//global variable
bool checking_succeed_searching = false;


///////////////////////////////////////////////////////////
///////////////////////Main Window/////////////////////////
///////////////////////////////////////////////////////////
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget -> setCurrentIndex(0);

    QPixmap pix("C:/programming-2/Final/Final/icons/Home.png");               //background image, change image address
    ui->backlabel->setPixmap(pix.scaled(800,800));          //set background image size, whole screen size

    QPixmap pixmap("C:/programming-2/Final/Final/icons/icon_Courses.png");   // Left big button image on the center,change image address
    QIcon ButtonIcon(pixmap);
    ui->pushButton->setIcon(ButtonIcon);
    ui->pushButton->setIconSize(QSize(155, 155));

    QPixmap pixmap2("C:/programming-2/Final/Final/icons/icon_Students.png");   // Right big button image on the center, change image address
    QIcon ButtonIcon_2(pixmap2);
    ui->pushButton_2->setIcon(ButtonIcon_2);
    ui->pushButton_2->setIconSize(QSize(155, 155));

    //////////Navigation//////////
    QPixmap course("C:/programming-2/Final/Final/icons/icon_Courses.png");   // First image of topright buttons, change image address
    QIcon ButtonIcon_N_1(course);
    ui->course->setIcon(ButtonIcon_N_1);
    ui->course->setIconSize(QSize(31, 31));
    QPixmap course_plus("C:/programming-2/Final/Final/icons/icon_plus_Courses.png");   // Second image of topright buttons, change image address
    QIcon ButtonIcon_N_2(course_plus);
    ui->course_plus->setIcon(ButtonIcon_N_2);
    ui->course_plus->setIconSize(QSize(31, 31));
    QPixmap stu("C:/programming-2/Final/Final/icons/icon_Students.png");     // Third image of topright buttons, change image address
    QIcon ButtonIcon_N_3(stu);
    ui->stu->setIcon(ButtonIcon_N_3);
    ui->stu->setIconSize(QSize(31, 31));
    QPixmap student_plus("C:/programming-2/Final/Final/icons/icon_plus_Students.png");   // Fourth image of topright buttons, change image address
    QIcon ButtonIcon_N_4(student_plus);
    ui->student_plus->setIcon(ButtonIcon_N_4);
    ui->student_plus->setIconSize(QSize(31, 31));
    QPixmap home("C:/programming-2/Final/Final/icons/icon_Home.png");        // Home button image of topleft button, change image address
    QIcon ButtonIcon_N_5(home);
    ui->home->setIcon(ButtonIcon_N_5);
    ui->home->setIconSize(QSize(31, 31));

    checking_succeed_searching = false;

    // DETAIL BUTTON. For more detail. //
    QPixmap pixmap3("C:/programming-2/Final/Final/icons/icon_search.png");
    QIcon detail_Pushbutton(pixmap3);
    ui->detail_Pushbutton->setIcon(detail_Pushbutton);
    // SAVING COURSES Window Page //
    QPixmap book("C:/programming-2/Final/Final/icons/icon_Courses.png");
    ui->book->setPixmap(book.scaled(100,100));
    // SEARCHING STUDENTS Window Page //
    QPixmap pixmap4("C:/programming-2/Final/Final/icons/icon_search.png");
    QIcon detail_Pushbutton_2(pixmap4);
    ui->detail_Pushbutton_2->setIcon(detail_Pushbutton_2);


    // SAVING STUDENTS Window Page //
    QPixmap book_2("C:/programming-2/Final/Final/icons/icon_Students.png");
    ui->book_2->setPixmap(book_2.scaled(100,100));


}

MainWindow::~MainWindow()
{
    delete ui;
}



///////////////////////////////////////////////////////////
////////////////////////Navigation/////////////////////////
///////////////////////////////////////////////////////////
//navigation - course button
void MainWindow::on_course_clicked()
{
    mydb = QSqlDatabase::addDatabase("QSQLITE");                         //code that loading sql based database
    mydb.setDatabaseName("C:/programming-2/Final/Final/course_db.db");   // load course_db database that we included, change address
    if(!mydb.open()){
        ui->label->setText("Failed to open the db");
    }else
        ui->label->setText("Connected...");
    mydb.open();

    QSqlQueryModel *model = new QSqlQueryModel(); //To visualize the database, make TableView table first
    QSqlQuery course_qry;
    course_qry.exec("SELECT Major, Course_name, Code, Credit, Prof FROM course_db");
    model->setQuery(course_qry);
    ui->tableView->setModel(model);

    ui->stackedWidget -> setCurrentIndex(1);
}
//navigation - course plus button
void MainWindow::on_course_plus_clicked()
{
    ui->stackedWidget -> setCurrentIndex(2);
}
//navigation - student button
void MainWindow::on_stu_clicked()
{
    mydb2 = QSqlDatabase::addDatabase("QSQLITE");                          //code that loading sql based database
    mydb2.setDatabaseName("C:/programming-2/Final/Final/student_db.db");   // load student_db database that we included, change address
    if(!mydb2.open()){
        ui->label_9->setText("Failed to open the db");
    }else
        ui->label_9->setText("Connected...");
    mydb2.open();

    QSqlQueryModel *model2 = new QSqlQueryModel(); //To visualize the database, make TableView table first
    QSqlQuery student_db2;
    student_db2.exec("SELECT Major, Name, Student_ID, Age, Gender, GPA FROM student_db");
    model2->setQuery(student_db2);
    ui->tableView_2->setModel(model2);


    ui->stackedWidget -> setCurrentIndex(3);
}
//navigation - student plus button
void MainWindow::on_student_plus_clicked()
{
    ui->stackedWidget -> setCurrentIndex(4);
}
//navigation - go to main page
void MainWindow::on_home_clicked()
{
    ui->stackedWidget -> setCurrentIndex(0);
}



///////////////////////////////////////////////////////////
////////////////////////<MAIN_PAGE>////////////////////////
///////////////////////////////////////////////////////////

// Left button of the center. Go to the course page(secdialog.ui)
void MainWindow::on_pushButton_clicked()
{
    mydb = QSqlDatabase::addDatabase("QSQLITE");                         //code that loading sql based database
    mydb.setDatabaseName("C:/programming-2/Final/Final/course_db.db");   // load course_db database that we included, change address
    if(!mydb.open()){
        ui->label->setText("Failed to open the db");
    }else
        ui->label->setText("Connected...");
    mydb.open();

    QSqlQueryModel *model = new QSqlQueryModel(); //To visualize the database, make TableView table first
    QSqlQuery course_qry;
    course_qry.exec("SELECT Major, Course_name, Code, Credit, Prof FROM course_db");
    model->setQuery(course_qry);
    ui->tableView->setModel(model);

    ui->stackedWidget -> setCurrentIndex(1);
}

// Right button of the center. Go to the course page(stu_1.ui)
void MainWindow::on_pushButton_2_clicked()
{

    mydb2 = QSqlDatabase::addDatabase("QSQLITE");                          //code that loading sql based database
    mydb2.setDatabaseName("C:/programming-2/Final/Final/student_db.db");   // load student_db database that we included, change address
    if(!mydb2.open()){
        ui->label_9->setText("Failed to open the db");
    }else
        ui->label_9->setText("Connected...");
    mydb2.open();

    QSqlQueryModel *model2 = new QSqlQueryModel(); //To visualize the database, make TableView table first
    QSqlQuery student_qry;
    student_qry.exec("SELECT Major, Name, Student_ID, Age, Gender, GPA FROM student_db");
    model2->setQuery(student_qry);
    ui->tableView_2->setModel(model2);

    ui->stackedWidget -> setCurrentIndex(3);
}


// < Searching Course >
void MainWindow::on_search_pushbutton_clicked()
{
    QString searchname = ui->search->text();
    QSqlQuery qry;

    if(qry.exec("select * from course_db where Major='"+searchname+"' or Course_name='"+searchname+"' or Code='"+searchname+"'")){
        qry.first();
        ui->major_search->setText(qry.value(0).toString());
        ui->course_search->setText(qry.value(1).toString());
        ui->code_search->setText(qry.value(2).toString());
        ui->credit_search->setText(qry.value(3).toString());
        ui->prof_search->setText(qry.value(4).toString());

        if(!ui->major_search->text().isEmpty()){
            //if succeed to search from the database, checking.
            checking_succeed_searching = true;
        }

    }else{
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
        //if fail to search from the database, re-checking.
        checking_succeed_searching = false;
        QMessageBox msgbox;
        msgbox.setText("Please, search what you want to see details, correctly");
        msgbox.exec();
    }

}

void MainWindow::on_Add_Pushbutton_clicked()
{
    ui->stackedWidget -> setCurrentIndex(2);
}


// < SAVING COURSES >
void MainWindow::on_Save_button_clicked()
{
    mydb.open();

    QString cour = ui->lineEdit ->text();
    QString code = ui->lineEdit_2 ->text();
    QString maj = ui->lineEdit_3 ->text();
    QString prof = ui->lineEdit_4 ->text();
    QString credit = ui->lineEdit_5 ->text();
    QString objective = ui->lineEdit_6 ->text();
    QString management = ui->lineEdit_7 ->text();

    QSqlQuery qry;

    if(qry.exec("insert into course_db (Major,Course_name,Code,Credit,Prof,Course_object,Course_management) values "
                "('"+maj+"','"+cour+"','"+code+"','"+credit+"','"+prof+"','"+objective+"','"+management+"')")){
        QMessageBox::question(this,tr("Save"),tr("Saved"));
        //mydb.close();
        }
    else{
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
        }
    mydb.close();
}


// < SEARCHING STUDENTS >
void MainWindow::on_Add_Pushbutton_2_clicked()
{
    ui->stackedWidget -> setCurrentIndex(4);
}

void MainWindow::on_search_pushbutton_2_clicked()
{
    QString searchname_2 = ui->search_2->text();
    QSqlQuery qry2;
    //qry.prepare();

    if(qry2.exec("select * from student_db where Name='"+searchname_2+"' or Student_ID='"+searchname_2+"'")){
        qry2.first();
        ui->student_major->setText(qry2.value(0).toString());
        ui->student_name->setText(qry2.value(1).toString());
        ui->student_id->setText(qry2.value(2).toString());
        ui->student_age->setText(qry2.value(3).toString());
        ui->student_gender->setText(qry2.value(4).toString());
        ui->student_gpa->setText(qry2.value(5).toString());

        if(!ui->student_name->text().isEmpty()){
            //if succeed to search from the database, checking.
            checking_succeed_searching = true;
        }
    }else{
        QMessageBox::critical(this,tr("error::"),qry2.lastError().text());
        //if fail to search from the database, re-checking.
        checking_succeed_searching = false;
    }

}


// < SAVING STUDENTS > // student_db
void MainWindow::on_Save_button_2_clicked()
{
    mydb2 = QSqlDatabase::database("QSQLITE", "First_connection");  //code that loading sql based database
    mydb2.setDatabaseName("C:/programming-2/Final/Final/student_db.db");   // load student_db database that we included, change address
    mydb2.open();

    QString major = ui->stu_major ->text();
    QString name = ui->stu_name ->text();
    QString id = ui->stu_id ->text();
    QString age = ui->stu_age ->text();
    QString gender = ui->stu_gender ->text();
    QString gpa = ui->stu_gpa ->text();

    QString major_2 = ui->stu_major_2 ->text();
    QString course_2 = ui->stu_course ->text();
    QString year_2 = ui->stu_year ->text();
    QString grade_2 = ui->stu_grade ->text();

    QString major_3 = ui->stu_major_3 ->text();
    QString course_3 = ui->stu_course_2 ->text();
    QString year_3 = ui->stu_year_2 ->text();
    QString grade_3 = ui->stu_grade_2 ->text();

    QString major_4 = ui->stu_major_4 ->text();
    QString course_4 = ui->stu_course_3 ->text();
    QString year_4 = ui->stu_year_3 ->text();
    QString grade_4 = ui->stu_grade_3 ->text();

    QSqlQuery qry2;
    QSqlQuery qry3;
    QSqlQuery qry4;
    QSqlQuery qry5;
    if(qry2.exec("insert into student_db (Major, Name, Student_ID, Age, Gender, GPA) values ('"+major+"','"+name+"','"+id+"','"+age+"','"+gender+"','"+gpa+"')")){
        //Users can record up to three courses taken by input students at a time.
        qry3.exec("insert into student_details (Major, Course, Year_Semester, Grade, Name, Student_ID) values ('"+major_2+"','"+course_2+"','"+year_2+"','"+grade_2+"','"+name+"','"+id+"')");
        qry4.exec("insert into student_details (Major, Course, Year_Semester, Grade, Name, Student_ID) values ('"+major_3+"','"+course_3+"','"+year_3+"','"+grade_3+"','"+name+"','"+id+"')");
        qry5.exec("insert into student_details (Major, Course, Year_Semester, Grade, Name, Student_ID) values ('"+major_4+"','"+course_4+"','"+year_4+"','"+grade_4+"','"+name+"','"+id+"')");

        QMessageBox::information(this,tr("Save"),tr("Saved"));
    }
    else{
        QMessageBox::critical(this,tr("error::write correctly"),qry2.lastError().text());
        }
    mydb2.close();

}



///////////////////////////////////////////////////////////
//////////////////////////Details//////////////////////////
///////////////////////////////////////////////////////////
void MainWindow::on_detail_Pushbutton_clicked()
{
    //adjust the contents's size of table
    ui->details_1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    mydb = QSqlDatabase::addDatabase("QSQLITE");  //code that loading sql based database
    mydb.setDatabaseName("C:/programming-2/Final/Final/course_db.db");   // load course_db database that we included, change address
    if(!mydb.open()){
        ui->label->setText("Failed to open the db");
    }else
        ui->label->setText("Connected...");

    mydb.open();

    //match the details with name of student
    QString searching;
    searching = ui->search->text();

    QSqlQueryModel *model_details1 = new QSqlQueryModel();
    QSqlQuery course_qry_details1;
    course_qry_details1.exec("SELECT Course_name, Course_object, Course_management FROM course_db WHERE Code='"+searching+"' or Course_name='"+searching+"' ");
    model_details1->setQuery(course_qry_details1);
    ui->details_1->setModel(model_details1);


    if(checking_succeed_searching){
        ui->stackedWidget -> setCurrentIndex(5);
    }else{
        QMessageBox msgbox;
        msgbox.setText("Please, search what you want to see details, first");
        msgbox.exec();
    }
    mydb.close();
}


void MainWindow::on_detail_Pushbutton_2_clicked()
{
    //adjust the contents's size of table
    ui->details_1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    mydb2 = QSqlDatabase::addDatabase("QSQLITE");  //code that loading sql based database
    mydb2.setDatabaseName("C:/programming-2/Final/Final/student_db.db");   // load student_db database that we included, change address

    mydb2.open();

    //match the details with name of student
    QString searching_student_details;
    searching_student_details = ui->search_2->text();

    QSqlQueryModel *model_student_details = new QSqlQueryModel();
    QSqlQuery student_qry_details;
    student_qry_details.exec("SELECT Major, Course, Year_Semester, Grade FROM student_details WHERE Name='"+searching_student_details+"' or Student_ID='"+searching_student_details+"' ");
    model_student_details->setQuery(student_qry_details);
    ui->details_1->setModel(model_student_details);


    if(checking_succeed_searching){
        ui->stackedWidget -> setCurrentIndex(5);
    }else{
        QMessageBox msgbox;
        msgbox.setText("Please, search what you want to see details, first");
        msgbox.exec();
    }
    mydb2.close();
}

