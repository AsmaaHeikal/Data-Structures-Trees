#ifndef DATA_STRUCTURES_TREES_AVL_H
#define DATA_STRUCTURES_TREES_AVL_H
#include<bits/stdc++.h>

#include "Student.h"
using namespace std;

class TreeNode{
public:
    Student data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){
        left = nullptr;
        right = nullptr;
    }
    explicit TreeNode(Student data){
        this->data = std::move(data);
        this->left = nullptr;
        this->right = nullptr;
    }
};

class AVL{
public:
    TreeNode * root;

    AVL(){
        root = nullptr;
    }

    int height(TreeNode * r){
        if(r== nullptr){
            return -1;
        }
        else{
            int lHeight=height(r->left);
            int rHeight=height(r->right);
            if(lHeight>rHeight)return lHeight+1;
            else return rHeight+1;
        }
    }

    int getBalanceFactor(TreeNode * n){
        if(n==nullptr)return -1;
        return height(n->left)-height(n->right);
    }

    TreeNode * rightRotate(TreeNode * n1){
        TreeNode * n2=n1->left;
        TreeNode * T=n2->right;
        n2->right=n1;
        n1->left=T;
        return n2;
    }

    TreeNode * leftRotate(TreeNode * n1){
        TreeNode * n2=n1->right;
        TreeNode * T= n2->left;
        n2->left=n1;
        n1->right=T;
        return n2;
    }

    TreeNode * insert(TreeNode * r,const Student& stud){
        auto * newNode =new TreeNode(stud);
        if(r==nullptr){
            r=newNode;
            return r;
        }
        else if(stoi(newNode->data.ID)<stoi(r->data.ID)){
            r->left=insert(r->left,stud);
        }
        else if(stoi(newNode->data.ID)>stoi(r->data.ID)){
            r->right=insert(r->right,stud);
        }
        else{
            return r;
        }

        int bf= getBalanceFactor(r);
        if(bf==2 && getBalanceFactor(r->left)>=0){
            return rightRotate(r);
        }
        else if(bf==2 && getBalanceFactor(r->left)==-1){
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }
        else if(bf==-2 && getBalanceFactor(r->right)<=0){
            return leftRotate(r);
        }
        else if(bf==-2 && getBalanceFactor(r->right)==1){
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }
        return r;
    }

    TreeNode * minValue(TreeNode * node){
        TreeNode * curr=node;
        while(curr ->left != nullptr){
            curr=curr->left;
        }
        return curr;
    }

   TreeNode * deleteNode(TreeNode * r,const Student& v){
        if(r==nullptr){
            return nullptr;
        }
        else if(stoi(v.ID) < stoi(r->data.ID)){
            r->left = deleteNode(r->left,v);
        }
        else if(stoi(v.ID) > stoi(r->data.ID)){
            r->right=deleteNode(r->right,v);
        }
        else{
            if(r->left==nullptr){
                TreeNode* temp=r->right;
                delete r;
                return temp;
            }
            else if(r->right == nullptr){
                TreeNode* temp=r->left;
                delete r;
                return temp;
            }
            else{
                TreeNode * temp=minValue(r->right);
                r->data=temp->data;
                r->right=deleteNode(r->right,temp->data);
            }
        }

        int bf= getBalanceFactor(r);
        if(bf==2 && getBalanceFactor(r->left)>=0){
            return rightRotate(r);
        }
        else if(bf==2 && getBalanceFactor(r->left)==-1){
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }
        else if(bf==-2 && getBalanceFactor(r->right)<=0){
            return leftRotate(r);
        }
        else if(bf==-2 && getBalanceFactor(r->right)==1){
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }
        return r;
    }

    TreeNode* search(TreeNode* r,const string& id){
        if(r== nullptr || r->data.ID==id){
            return r;
        }
        else if(stoi(id)<stoi(r->data.ID)){
            return search(r->left,id);
        }
        else {
            return search(r->right,id);
        }
    }

    void printDataInTreeNode(TreeNode* r){
        if(r== nullptr){
            return;
        }
        r->data.printStudent();
    }

    void print(TreeNode* r){
        if(r== nullptr){
            return;
        }
        print(r->left);
        r->data.printStudent();
        print(r->right);
    }
};

int loadFromFileIntoTree(AVL& tree){
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
        tree.root=tree.insert(tree.root,stud);
    }
    file.close();
    return studentNum;
}


void numOfStudentsInEachDepartment(TreeNode * r,map<string,int>& m){
    if(r== nullptr)return;
    numOfStudentsInEachDepartment(r->left,m);
    m[r->data.department]++;
    numOfStudentsInEachDepartment(r->right,m);
}

void printNumOfStudentsInEachDepartment(AVL & tree){
    map<string,int>m;
    numOfStudentsInEachDepartment(tree.root,m);
    for(auto & it : m){
        cout<<it.first<<" "<<it.second<<" Students"<<endl;
    }
}

void addStudent(AVL & tree){
    string id;cout<<"id: ";cin>>id;
    string name;cout<<"name: ";cin>>name;
    string gpa;cout<<"gpa: ";cin>>gpa;
    string department;cout<<"department: ";cin>>department;
    Student stud{name,id,gpa, department};
    tree.root=tree.insert(tree.root,stud);
    if(tree.root!= nullptr){
        cout<<"The student is added."<<endl;
    }
}

void removeStudent(AVL & tree){
    string id;cout<<"id: ";cin>>id;
    auto student=tree.search(tree.root,id);
    if(student== nullptr){
        cout<<"The student is not found."<<endl;
    }
    else{
        cout<<"The student is found."<<endl;
        tree.printDataInTreeNode(student);
        if(tree.deleteNode(tree.root,student->data)!= nullptr){
            cout<<"The student is removed."<<endl;
        }
    }
}

void searchStudent(AVL & tree){
    string id;cout<<"id: ";cin>>id;
    auto student=tree.search(tree.root,id);
    if(student== nullptr){
        cout<<"The student is not found."<<endl;
    }
    else{
        cout<<"The student is found."<<endl;
        tree.printDataInTreeNode(student);
    }
}

void printStudents(AVL & tree){
    tree.print(tree.root);
    printNumOfStudentsInEachDepartment(tree);
}

#endif //DATA_STRUCTURES_TREES_AVL_H
