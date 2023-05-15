#include<bits/stdc++.h>
#include "Student.h"
#include "minHeap.h"
#include "maxHeap.h"
#include "AVL.h"

using namespace std;


int main(){

    //The first menu
    int choice=0;
    while(true){
        cout<<"Welcome!Choose the data structure:\n"
              "1. BST\n"
              "2. AVL\n"
              "3. Min Heap\n"
              "4. Max Heap\n"
              "5. Exit Program"<<endl;
        cin>>choice;
            //BST Menu
        if(choice==1) {
            cout << "Choose one of the following options:\n"
                    "1. Add student \n"
                    "2. Remove student\n"
                    "3. Search student\n"
                    "4. Print All (sorted by id)\n"
                    "5. Return to main menu" << endl;
        }
            //AVL Menu
        if(choice==2) {
            cout << "Choose one of the following options:\n"
                    "1. Add student \n"
                    "2. Remove student\n"
                    "3. Search student\n"
                    "4. Print All (sorted by id)\n"
                    "5. Return to main menu" << endl;
            int choice2;
            cin >> choice2;

            AVL avl;
            loadFromFileIntoTree(avl);
            while(true) {
                if (choice2 == 1) {
                    addStudent(avl);
                } else if (choice2 == 2) {
                    removeStudent(avl);
                } else if (choice2 == 3) {
                    searchStudent(avl);
                } else if (choice2 == 4) {
                    printStudents(avl);
                } else if (choice2 == 5) {
                    break;
                }
                cout << "Choose one of the following options:\n"
                        "1. Add student \n"
                        "2. Remove student\n"
                        "3. Search student\n"
                        "4. Print All (sorted by id)\n"
                        "5. Return to main menu" << endl;
                cin >> choice2;
            }
        }
        if(choice==3) {
            int minHeapChoice;
            cout << "Choose one of the following options:\n"
                    "1. Add student\n"
                    "2. Print All (sorted by gpa)" << endl;
            cin >> minHeapChoice;
            if (minHeapChoice == 1) {
                Student student;
                minHeap minheap;
                cout << "Please enter your name: " << endl;
                cin >> student.name;
                cout << "Please enter your ID: " << endl;
                cin >> student.ID;
                cout << "Please enter your GPA: " << endl;
                cin >> student.GPA;
                cout << "Please enter your department: " << endl;
                cin >> student.department;
                addStudent(student, minheap);
            } else if (minHeapChoice == 2) {
                minHeap minheap;
                printAll(minheap);
            } else
                cout << "Invalid input";
        }
        if(choice==4) {
            int maxHeapChoice;
            maxHeap maxheap;
            cout << "Choose one of the following options:\n"
                    "1. Add student\n"
                    "2. Print All (sorted by gpa)" << endl;
            cin >> maxHeapChoice;
            if (maxHeapChoice == 1) {
                Student student;
                cout << "Please enter your name: " << endl;
                cin >> student.name;
                cout << "Please enter your ID: " << endl;
                cin >> student.ID;
                cout << "Please enter your GPA: " << endl;
                cin >> student.GPA;
                cout << "Please enter your department: " << endl;
                cin >> student.department;
//                    addStudent(student, maxheap);
            }
            if (maxHeapChoice == 2) {
//                    printAll(maxheap);
            }
        }
        if(choice==5){
            break;
        }
    }
}