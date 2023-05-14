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
    minHeap(const vector<Student> &minHeapv) : minHeapv(minHeapv) {}

    minHeap() {}

    int size=minHeapv.size();

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
        if(isEmpty())
            cout<<"This heap is empty";
        return minHeapv[0];
    }

    void removeMin(){
        minHeapv[0]=minHeapv[getSize()-1];
        size--;
        heapify(0);

    }

};
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

#endif //MINHEAP_ASSIGNMENT3_DS_MINHEAP_H
