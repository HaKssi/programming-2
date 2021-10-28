//student_id : 21800197
//introduction : show my name and student id

//basic setting
#include <iostream>
using namespace std;

//defining name and student id in macro
#define MY_NAME         "Kim HakSenog"
#define MY_STUDENT_ID   21800197

//main fuction
int main(){
    cout << "My name is "<< MY_NAME << endl;                //print name
    cout << "My student ID is " << MY_STUDENT_ID << endl;   //print student id
    return 0;
}
