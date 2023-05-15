#ifndef MINHEAP_ASSIGNMENT3_DS_MINHEAP_H
#define MINHEAP_ASSIGNMENT3_DS_MINHEAP_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Student.h"
using namespace std;

class minHeap{
private:
    vector<Student>minHeapv;
public:
    minHeap(const vector<Student> &minHeapv) : minHeapv(minHeapv) {
        for (int i = minHeapv.size() / 2 - 1; i >= 0; i--)
            heapify(i);
    }

    minHeap() {
    }


    int parent(int index){
        return (index-1)/2;
    }
    //The heapify function takes the vector and transforms it into a minHeap
    void heapify(int index){
        int leftChild=2*index+1;
        int rightChild=2*index+2;
        int smallest=index;
        //if the left child is smaller than the assumed smaller number then we make the new "smallest" value the left child
        if(minHeapv[leftChild].GPA<minHeapv[smallest].GPA) {
            smallest = leftChild;
        }
        //if the right child is smaller than the assumed smaller number then we make the new "smallest" value the right child
        if(minHeapv[rightChild].GPA<minHeapv[smallest].GPA) {
            smallest = rightChild;
        }
        //We loop until the variable smallest no longer carries the index value and when it doesn't we swap them
        if(smallest!=index) {
            swap(minHeapv[index], minHeapv[smallest]);
            heapify(smallest);
        }
    }

    void insert(Student val){
        minHeapv.push_back(val);
        //The index of the new element inside the heap
        int index=minHeapv.size()-1;
        while(index>0 && minHeapv[index].GPA<minHeapv[parent(index)].GPA){
            swap(minHeapv[index], minHeapv[parent(index)]);
            index= parent(index);
        }

    }

    void copyVector(vector<Student> &vec)
    {
//        size = vec.size();
//        minHeapv.resize(size);
        minHeapv = vec;
        cout << "Students Added successfully " << endl;
    }

    int getSize(){
        return minHeapv.size();
    }

    bool isEmpty(){
        if(getSize()==0)
            return true;
        else
            return false;
    }

    Student getMin(){
        if(isEmpty()) {
            cout << "This heap is empty";
//            return Student();
        }
        return minHeapv[0];
    }

    void removeMin(){
        if (!isEmpty()) {
            minHeapv[0] = minHeapv[getSize() - 1];
            minHeapv.pop_back();
            heapify(0);
        }
    }


};
    //Function to add a student to a min heap
    void minAddStudent(minHeap& minheap){
        Student student;
        cout << "Please enter your name: " << endl;
        cin >> student.name;
        cout << "Please enter your ID: " << endl;
        cin >> student.ID;
        cout << "Please enter your GPA: " << endl;
        cin >> student.GPA;
        cout << "Please enter your department: " << endl;
        cin >> student.department;
        minheap.insert(student);
        cout<<"The student is added"<<endl;
    }
    int loadFromFileIntoTree(minHeap& tree){
        ifstream file("input.txt");
        if (!file.is_open()) {
            cout << "Failed to open the file: "  << endl;
            return 0;
        }
        int studentNum;
        file>>studentNum;
        file.ignore();
        for(int i=0;i<studentNum;i++){
            Student stud;
            getline(file,stud.ID);
            getline(file,stud.name);
            getline(file,stud.GPA);
            getline(file,stud.department);
            tree.insert(stud);
            file.ignore();
        }
        file.close();
        return studentNum;
    }
    //Print all students in the file sorted in ascending order
    void printAll(minHeap& minheap) {
        while(!minheap.isEmpty()){
            Student student=minheap.getMin();
            student.printStudent();
            minheap.removeMin();
        }
    }


    #endif //MINHEAP_ASSIGNMENT3_DS_MINHEAP_H
