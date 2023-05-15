#ifndef MINHEAP_ASSIGNMENT3_DS_MAXHEAP_H
#define MINHEAP_ASSIGNMENT3_DS_MAXHEAP_H
#include <iostream>
#include<vector>
#include<algorithm>
#include "Student.h"
using namespace std;
class maxHeap{
private:
    vector<Student>maxHeapv;
public:
    maxHeap() {}

    maxHeap(const vector<Student> &maxHeapv) : maxHeapv(maxHeapv) {}

    int parent(int index){
        return (index-1)/2;
    }
    int size=maxHeapv.size();

    //The heapify function takes the vector and transforms it into a minHeap
    void heapify(int index){
        int leftChild=2*index+1;
        int rightChild=2*index+2;
        int largest=index;
        //if the left child is smaller than the assumed smaller number then we make the new "smallest" value the left child
        if(maxHeapv[leftChild].GPA>maxHeapv[largest].GPA) {
            largest = leftChild;
        }
        //if the right child is smaller than the assumed smaller number then we make the new "smallest" value the right child
        if(maxHeapv[rightChild].GPA>maxHeapv[largest].GPA) {
            largest = rightChild;
        }
        //We loop until the variable smallest no longer carries the index value and when it doesn't we swap them
        if(largest!=index) {
            swap(maxHeapv[index], maxHeapv[largest]);
            heapify(largest);
        }
    }

    void insert(Student val){
        maxHeapv.push_back(val);
        //The index of the new element inside the heap
        int index=maxHeapv.size()-1;
        while(index>0 && maxHeapv[index].GPA>maxHeapv[parent(index)].GPA){
            swap(maxHeapv[index], maxHeapv[parent(index)]);
            index= parent(index);
        }

    }

    int getSize(){
        return maxHeapv.size();
    }

    bool isEmpty(){
        if(getSize()==0)
            return true;
        else
            return false;
    }

    Student getMax(){
        if(isEmpty())
            cout<<"This heap is empty";
        return maxHeapv[0];
    }

    void removeMax(){
        maxHeapv[0]=maxHeapv[getSize()-1];
        size--;
        heapify(0);

    }


};
//Function to a student to the max heap
void maxAddStudent(maxHeap& maxheap){
    Student student;
    cout << "Please enter your name: " << endl;
    cin >> student.name;
    cout << "Please enter your ID: " << endl;
    cin >> student.ID;
    cout << "Please enter your GPA: " << endl;
    cin >> student.GPA;
    cout << "Please enter your department: " << endl;
    cin >> student.department;
    maxheap.insert(student);
    cout<<"The student is added"<<endl;
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

#endif //MINHEAP_ASSIGNMENT3_DS_MAXHEAP_H
