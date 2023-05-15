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

    BSTNode *search(BSTNode *node, int id) {
        if (node == nullptr || node->data.ID == id) {
            return node;
        } else if (id < node->data.ID) {
            return search(node->left, id);
        } else {
            return search(node->right, id);
        }
    }

    BSTNode *remove(BSTNode *node, int id) {
        if (node == nullptr) {
            cout << "Student not found" << endl;
            return nullptr;
        }

        if (id < node->data.ID) {
            node->left = remove(node->left, id);
        } else if (id > node->data.ID) {
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
            if(current->data.department == "CS")
                cs++;
            else if(current->data.department == "AI")
                ai++;
            else if(current->data.department == "IS")
                is++;
            else if(current->data.department == "DS")
                ds++;
            else if(current->data.department == "IT")
                it++;

            cout << "[ " << current->data.ID << ", " << current->data.name << ", " << current->data.GPA << ", "
                 << current->data.department << " ]" << endl;
            current = current->right;
            cout<<endl<<"Students per department:"<<endl;
            cout<<"CS "<<cs<<" Students\nIT "<<it<<" Students\nDS "<<ds<<" Students\nIS "<<is<<" Students\nAI "<<ai
            <<" Students"<<endl;
        }

    }

private:
    BSTNode *min(BSTNode *node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};