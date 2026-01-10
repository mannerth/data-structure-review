#include<iostream>
using namespace std;

template<class T>
class binaryTreeNode{

public:
    T data;
    binaryTreeNode* left, *right;
    binaryTreeNode(const T& d):data(d){
        left = nullptr;
        right = nullptr;
    }

    binaryTreeNode(const T& d, binaryTreeNode* l, binaryTreeNode* r)
        :data(d), left(l), right(r){

    }

};

template<class T>
class binaryTree{

private:
    int size;
    binaryTreeNode<T>* root;

public:
    binaryTree(){
        size = 0;
        root = nullptr;
    }

    void setRoot(const binaryTreeNode<T>* r){
        root = r;
    }

    void inOrder( binaryTreeNode<T>* node, void (*opt) (T d) );
};