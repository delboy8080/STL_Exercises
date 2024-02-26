#include <iostream>
#include <map>
#include "Solutions.h"
using namespace std;
typedef void (*func)();

int main() {
   map<int, func> questions;
   questions[1] = question1;
    questions[2] = question2;
    questions[3] = question3;
    questions[4] = question4;
    questions[5] = question5;
    questions[6] = question6;
    questions[7] = question7;
    questions[8] = question8;
    questions[9] = question9;
    questions[10] = question10;
    questions[11] = question11;
    questions[12] = question12;

    int choice = 0;
    string temp;
    do {
        cout << "Please enter question number to run, -1 to end"<<endl;
        cin >> choice;
        getline(cin, temp);
        cout << endl;
        if(questions.count(choice))
        {
           questions[choice]();
        }
        else
        {
            cout << "invalid input."<<endl;
        }
        cout << "\n\n\n";
    }while(choice!=-1);




    return 0;
}
