
#ifndef DATA_STRUCTURES_BST_H
#define DATA_STRUCTURES_BST_H

#include <iostream>
#include <stack>
#include "Student.h"

using namespace std;

struct BSTNode {
    Student data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(Student s) : data(s), left(nullptr), right(nullptr) {}
};

void numOfStudentsInEachDepartment(BSTNode * r,map<string,int>& m){
    if(r== nullptr)return;
    numOfStudentsInEachDepartment(r->left,m);
    m[r->data.department]++;
    numOfStudentsInEachDepartment(r->right,m);
}

class BST {


public:
    BSTNode *root;
    BST() : root(nullptr) {}

    void setRoot(BSTNode *r) {
        this->root = r;
    }

    BSTNode *getRoot() const {
        return root;
    }

    BSTNode *insert(BSTNode *node, Student s) {
        if (node == nullptr) {
            node = new BSTNode(s);
            if (root == nullptr) {
                root = node;
            }
        } else if (stoi(s.ID) < stoi(node->data.ID)) {
            node->left = insert(node->left, s);
        } else {
            node->right = insert(node->right, s);
        }
        return node;
    }

    BSTNode *search(BSTNode *node, string id) {
        if (node == nullptr || node->data.ID == id) {
            return node;
        } else if (stoi(id) < stoi(node->data.ID)) {
            return search(node->left, id);
        } else {
            return search(node->right, id);
        }
    }

    BSTNode *remove(BSTNode *node, string id) {
        if (node == nullptr) {
            return nullptr;
        }
        if (stoi(id) < stoi(node->data.ID)) {
            node->left = remove(node->left, id);

        } else if (stoi(id) > stoi(node->data.ID)) {
            node->right = remove(node->right, id);

        } else {
            if (node->left == nullptr) {
                BSTNode *temp = node->right;
                delete node;
                return temp;

            } else if (node->right == nullptr) {
                BSTNode *temp = node->left;
                delete node;
                return temp;
            }
            BSTNode *temp = min(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data.ID);
        }
        return node;
    }

    void print(BSTNode* r){
        if(r== nullptr)return;
        print(r->left);
        r->data.printStudent();
        print(r->right);
    }

private:
    BSTNode *min(BSTNode *node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};

void printNumOfStudentsInEachDepartment(BST & tree){
    map<string,int>m;
    numOfStudentsInEachDepartment(tree.root,m);
    for(auto & it : m){
        cout<<it.first<<" "<<it.second<<" Students"<<endl;
    }
}

int loadFromFile(BST &b) {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cout << "Failed to open the file: " << endl;
        return 0;
    }
    int studentNum;
    file >> studentNum;
    file.ignore();
    for (int i = 0; i < studentNum; i++) {
        Student stud;
        getline(file, stud.ID);
        getline(file, stud.name);
        getline(file, stud.GPA);
        getline(file, stud.department);
        b.setRoot(b.insert(b.getRoot(), stud));
    }
    file.close();
    return studentNum;


}

void addStudent(BST &b) {
    string id;
    cout << "id:";
    cin >> id;
    string name;
    cout << "name:";
    cin >> name;
    string gpa;
    cout << "gpa:";
    cin >> gpa;
    string department;
    cout << "department:";
    cin >> department;
    Student stud{name, id, gpa, department};
    b.setRoot(b.insert(b.getRoot(), stud));

}

void searchStudent(BST &b) {
    string id;
    cout << "id:";
    cin >> id;
    BSTNode *student = b.search(b.getRoot(), id); // Search for the node with ID 2
    if (student != nullptr) {
        cout << "Found student\n";
        student->data.printStudent();
    } else {
        cout << "Student not found." << endl;
    }
}

void removeStudent(BST &b) {
    string id;
    cout << "id:";
    cin >> id;
    auto student = b.search(b.getRoot(), id);

    if (student != nullptr) {
        cout << "Found student\n" ;
        student->data.printStudent();
        b.remove(b.getRoot(), id);
    } else {
        cout << "Student not found." << endl;
    }
}

void printStudents(BST & tree){
    tree.print(tree.root);
    printNumOfStudentsInEachDepartment(tree);
}
#endif //DATA_STRUCTURES_BST_H
