
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

class BST {
private:
    BSTNode *root;

public:
    BST() : root(nullptr) {}

    void setRoot(BSTNode *root) {
        BST::root = root;
    }

    BSTNode *getRoot() const {
        return root;
    }

    BSTNode *insert(BSTNode *node, Student s) {
        if (node == nullptr) {
            node = new BSTNode(s);
            cout << "The student is added" << endl;
            if (root == nullptr) {
                root = node;
            }
        } else if (s.ID < node->data.ID) {
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
            cout << "Student not found" << endl;
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
                cout << "Student is deleted" << endl;
                return temp;

            } else if (node->right == nullptr) {
                BSTNode *temp = node->left;
                delete node;
                cout << "Student is deleted" << endl;
                return temp;
            }
            BSTNode *temp = min(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data.ID);
        }
        return node;
    }

    void print() {
        int cs = 0, ds = 0, it = 0, ai = 0, is = 0;
        if (root == nullptr) {
            cout << "The tree is empty." << endl;
            return;
        }

        stack<BSTNode *> s;
        BSTNode *current = root;
        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            if (current->data.department == "CS")
                cs++;
            else if (current->data.department == "AI")
                ai++;
            else if (current->data.department == "IS")
                is++;
            else if (current->data.department == "DS")
                ds++;
            else if (current->data.department == "IT")
                it++;

            cout << "[" << current->data.ID << ", " << current->data.name << ", " << current->data.GPA << ", "
                 << current->data.department << "]" << endl;
            current = current->right;

        }
        cout << endl << "Students per department:" << endl;
        cout << "CS " << cs << " Students\nIT " << it << " Students\nDS " << ds << " Students\nIS " << is
             << " Students\nAI " << ai << " Students" << endl;

    }

private:
    BSTNode *min(BSTNode *node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};

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
        cout << "Found student\n" << "[" << student->data.ID << ", " << student->data.name << ", "
             << student->data.GPA << ", " << student->data.department << "]" << endl;
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
        cout << "Found student\n" << "[" << student->data.ID << ", " << student->data.name << ", "
             << student->data.GPA << ", " << student->data.department << "]" << endl;
        b.remove(b.getRoot(), id);
    } else {
        cout << "Student not found." << endl;
    }


}

#endif //DATA_STRUCTURES_BST_H
