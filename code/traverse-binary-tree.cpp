#include<iostream>
#include<stack>
#include<vector>
#include"../code/model/binary-tree.cpp"

// 中序遍历非递归
template<class T>
void inOrder(binaryTreeNode<T>* node, void (*opt)(T v) ){

    stack< binaryTreeNode<T>* > stk;
    binaryTreeNode<int>* p = node;

    do{
        while(p){
            stk.push(p);
            p = p->left;
        }
        if( !stk.empty() ){
            p = stk.top();
            stk.pop();
            opt(p->data);
            p = p->right;
        }
    }while( p || !stk.empty() );

};

void print(int v){
    cout << v << endl;
}

int main(){

    binaryTreeNode<int> node(
        1, 
        new binaryTreeNode<int>(
            2, 
            nullptr,
            new binaryTreeNode<int>(
                4,
                new binaryTreeNode<int>(
                    5
                ),
                nullptr
            )
        ),
        new binaryTreeNode<int>(
            3,
            nullptr,
            new binaryTreeNode<int>(
                6,
                new binaryTreeNode<int>(
                    7,
                    new binaryTreeNode<int>(8),
                    new binaryTreeNode<int>(9)
                ),
                nullptr
            )
        )
    );

    void (*f)(int v) = print;
    inOrder<int>( &node, [](int a){ cout << a << endl;} );


    return 0;
}