#include<iostream>
#include<stack>
#include<queue>
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

    binaryTreeNode<T>* getRoot(){
        return root;
    } 

    /// 层次序创建完全二叉树
    static binaryTree buildByLevelOrder(T *vals, int size){
        binaryTree instance{};
        if(size==0 || !vals){
            return instance;
        }

        instance.root = new binaryTreeNode<T>(vals[0]);
        instance.size = 1;

        queue<binaryTreeNode<T>*> que;
        que.push(instance.root);

        binaryTreeNode<T>* p;
        while( !que.empty() && instance.size < size ){
            p = que.front();
            que.pop();

            p->left = new binaryTreeNode<T>( vals[instance.size++] );
            que.push(p->left);

            if(instance.size == size) break;

            p->right = new binaryTreeNode<T>( vals[instance.size++] );
            que.push(p->right);
        }

        return instance;
    }

    void inOrder( void (*opt) (T d) );

    void door( void (*func)(binaryTree<T> ) ){
        func(this);
    }
};