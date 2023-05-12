#include "minHeap.h"
#include "maxHeap.h"
//Function to add a student to a min heap
void addStudent(Student student, minHeap &minheap){
    minheap.insert(student);
    cout<<"The student is added"<<endl;
}
//Print all students in the file sorted in ascending order
void printAll(minHeap& minheap) {
    for(int i=0;i<minheap.getSize();i++) {
        Student student=minheap.getMin();
        cout << "ID: " << student.ID << endl;
        cout << "Name: " << student.name << endl;
        cout << "GPA: " << student.GPA << endl;
        cout << "Department: " << student.department << endl;
        cout << endl;
        minheap.removeMin();
    }
}
//Print all students in the file sorted in descending order
void printAll(maxHeap& maxheap) {
    for(int i=0;i<maxheap.getSize();i++) {
        Student student=maxheap.getMax();
        cout << "ID: " << student.ID << endl;
        cout << "Name: " << student.name << endl;
        cout << "GPA: " << student.GPA << endl;
        cout << "Department: " << student.department << endl;
        cout << endl;
        maxheap.removeMax();
    }
}
//Function to a student to the max heap
void addStudent(Student student, maxHeap &maxheap){
    maxheap.insert(student);
    cout<<"The student is added"<<endl;
}

// function to read data from file and store in vectors
void readDataFromFile(string heap, vector<int>& ids, vector<string>& names, vector<float>& gpas, vector<string>& departments) {
    ifstream infile("heap.txt");
    int num_students;
    infile >> num_students;
    for (int i = 0; i < num_students; i++) {
        int id;
        string name;
        float gpa;
        string department;
        infile >> id >> name >> gpa >> department;
        ids.push_back(id);
        names.push_back(name);
        gpas.push_back(gpa);
        departments.push_back(department);
    }
    infile.close();
}
int main(){

    //The first menu
    int choice;
    while(choice!=5){
        cout<<"Welcome!Choose the data structure:\n"
              "1. BST\n"
              "2. AVL\n"
              "3. Min Heap\n"
              "4. Max Heap\n"
              "5. Exit Program"<<endl;
        cin>>choice;
        switch (choice) {
            //BST Menu
            case 1:
                cout<<"Choose one of the following options:\n"
                      "1. Add student \n"
                      "2. Remove student\n"
                      "3. Search student\n"
                      "4. Print All (sorted by id)\n"
                      "5. Return to main menu"<<endl;
                break;
            //AVL Menu
            case 2:
                cout<<"Choose one of the following options:\n"
                      "1. Add student \n"
                      "2. Remove student\n"
                      "3. Search student\n"
                      "4. Print All (sorted by id)\n"
                      "5. Return to main menu"<<endl;
                break;
            //Min Heap
            case 3:
                int minHeapChoice;
                cout<<"Choose one of the following options:\n"
                      "1. Add student\n"
                      "2. Print All (sorted by gpa)"<<endl;
                cin>>minHeapChoice;
                if(minHeapChoice==1) {
                    Student student;
                    minHeap minheap;
                    cout<<"Please enter your name: "<<endl;
                    cin>>student.name;
                    cout<<"Please enter your ID: "<<endl;
                    cin>>student.ID;
                    cout<<"Please enter your GPA: "<<endl;
                    cin>>student.GPA;
                    cout<<"Please enter your department: "<<endl;
                    cin>>student.department;
                    addStudent(student, minheap);
                }

                else if(minHeapChoice==2){
                    minHeap minheap;
                    printAll(minheap);
                }
                else
                    cout<<"Invalid input";
                break;
             //Max Heap
            case 4:
                int maxHeapChoice;
                maxHeap maxheap;
                cout<<"Choose one of the following options:\n"
                      "1. Add student\n"
                      "2. Print All (sorted by gpa)"<<endl;
                cin>>maxHeapChoice;
                if(maxHeapChoice==1){
                    Student student;
                    cout<<"Please enter your name: "<<endl;
                    cin>>student.name;
                    cout<<"Please enter your ID: "<<endl;
                    cin>>student.ID;
                    cout<<"Please enter your GPA: "<<endl;
                    cin>>student.GPA;
                    cout<<"Please enter your department: "<<endl;
                    cin>>student.department;
                    addStudent(student, maxheap);
                }
                if(maxHeapChoice==2){
                    printAll(maxheap);
                }

                break;
        }

    }

}