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
        else if(newNode->data.ID<r->data.ID){
            r->left=insert(r->left,stud);
        }
        else if(newNode->data.ID>r->data.ID){
            r->right=insert(r->right,stud);
        }
        else{
            return r;
        }

        int  bf= getBalanceFactor(r);
        if(bf>1 &&  newNode->data.ID < r->left->data.ID) return rightRotate(r);
        else if(bf<-1 && newNode->data.ID > r->right->data.ID) return leftRotate(r);
        else if(bf>1 && newNode->data.ID > r->left->data.ID) {
            r->left= leftRotate(r->left);
            return rightRotate(r);
        }
        else if(bf<-1 &&newNode->data.ID < r->right->data.ID){
            r->right= rightRotate(r->right);
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
        else if(v.ID < r->data.ID){
            r->left = deleteNode(r->left,v);
        }
        else if(v.ID > r->data.ID){
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

    TreeNode* search(TreeNode* r,const Student& stud){
        if(r== nullptr || r->data.ID==stud.ID){
            return r;
        }
        else if(stud.ID<r->data.ID){
            return search(r->left,stud);
        }
        else {
            return search(r->right,stud);
        }
    }

    void print(TreeNode* r){
        if(r== nullptr)return;
        print(r->left);
        cout<<'['<<r->data.ID<<", "<<r->data.name<<", "<<r->data.GPA<<", "<<r->data.department<<']'<<endl;
        print(r->right);
    }
};
#endif //DATA_STRUCTURES_TREES_AVL_H
