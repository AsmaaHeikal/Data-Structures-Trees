#ifndef DATA_STRUCTURES_TREES_STUDENT_H
#define DATA_STRUCTURES_TREES_STUDENT_H
#include<bits/stdc++.h>
using namespace std;

struct Student{
    string name;
    string ID;
    string GPA;
    string department;
    Student(string name, string ID, string GPA, string department){
        this->name = std::move(name);
        this->ID = ID;
        this->GPA = GPA;
        this->department = std::move(department);
    }
    Student(){
        name = "";
        ID = "";
        GPA = "";
        department = "";
    }

    void printStudent(){
        cout<<'['<<ID<<", "<<name<<", "<<GPA<<", "<<department<<']'<<endl;
    }
};

#endif //DATA_STRUCTURES_TREES_STUDENT_H
