#include "minHeap.h"
#include "maxHeap.h"
#include<bits/stdc++.h>
#include "Student.h"
#include "AVL.h"

using namespace std;


int main(){

    //The first menu
    int choice = 0, choice2;
    while(true){
        cout<<"Welcome! Choose the data structure:\n"
              "1. BST\n"
              "2. AVL\n"
              "3. Min Heap\n"
              "4. Max Heap\n"
              "5. Exit Program"<<endl;
        cin>>choice;
        //BST Menu
        if (choice == 1) {
            cout << "Choose one of the following options:\n"
                    "1. Add student \n"
                    "2. Remove student\n"
                    "3. Search student\n"
                    "4. Print All (sorted by id)\n"
                    "5. Return to main menu" << endl;

            //insert choice form menu 2
            cin >> choice2;
            BST bst;
            //load info from file to BST
            loadFromFile(bst);

            while (true) {
                if (choice2 == 1) {
                    addStudent(bst);
                } else if (choice2 == 2) {
                    removeStudent(bst);
                } else if (choice2 == 3) {
                    searchStudent(bst);
                } else if (choice2 == 4) {
                    bst.print();
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
        //AVL Menu
        if(choice==2) {
            cout << "Choose one of the following options:\n"
                    "1. Add student \n"
                    "2. Remove student\n"
                    "3. Search student\n"
                    "4. Print All (sorted by id)\n"
                    "5. Return to main menu" << endl;
            
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
        //Minheap menu
        if(choice==3) {
            Student student;
            minHeap minheap;
            vector<Student> te;
            loadFromFileIntoTree(minheap);
            
            cout << "Choose one of the following options:\n"
                    "1. Add student\n"
                    "2. Print All (sorted by gpa)\n"
                    "3. Return to the main menu"<<endl;

            cin >> choice2;
            while(true){
                if (choice2 == 1) {
                    minAddStudent(minheap);
                } else if (choice2 == 2) {
                    printAll(minheap);
                } else if(choice2==3) {
                    break;
                }
                cout << "Choose one of the following options:\n"
                         "1. Add student\n"
                         "2. Print All (sorted by gpa)\n"
                         "3. Return to the main menu"<<endl;

                cin >> choice2;
            }

        }
        //Maxheap choice
        if(choice==4) {
            
            maxHeap maxheap;
            Student student;
            cout << "Choose one of the following options:\n"
                    "1. Add student\n"
                    "2. Print All (sorted by gpa)\n"
                    "3. Return to the main menu"<<endl;
            cin >> choice2;
            while(true){
                if (choice2 == 1) {
                    maxAddStudent(maxheap);
                } else if (choice2 == 2) {
                    printAll(maxheap);
                } else if(choice2 == 3) {
                    break;
                }cout << "Choose one of the following options:\n"
                         "1. Add student\n"
                         "2. Print All (sorted by gpa)\n"
                         "3. Return to the main menu"<<endl;
                cin >> choice2;

            }
                    }
        if(choice==5){
            break;
        }
    }
}
