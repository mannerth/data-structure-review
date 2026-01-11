#include<iostream>
#include<stack>
#include<vector>
#include"../code/model/binary-tree.cpp"

// 中序遍历非递归
template<class T>
void _inOrder(binaryTreeNode<T>* node, void (*opt)(T v) ){

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

template<class T>
void binaryTree<T>::inOrder( void (*opt)(T val) ){
    _inOrder<T>(this->root, opt);
}

// 前序遍历非递归实现
template<class T>
void _preOrder( binaryTreeNode<T>* node, void (*func)(T val) ){
    binaryTreeNode<T>* p = node;
    stack< binaryTreeNode<T>* > stk;

    while( !stk.empty() || p ){
        while( p ){
            func(p->data);
            stk.push(p);
            p = p->left;
        }
        if( !stk.empty() ){
            p = stk.top();
            stk.pop();

            p = p->right;
        }
    }
}

// 后序遍历非递归
template<class T>
void _lastOrder( binaryTreeNode<T>* node, void (*func)(T val) ){
    //后序遍历，先访问左右子，再访问本节点
    //第二次相见时才访问

    binaryTreeNode<T>* p = node;
    stack< binaryTreeNode<T>* > stk;

    int flag;
    stack< int > fs;    //标志位

    while( !stk.empty() || p ){
        while( p ){
            stk.push(p);
            fs.push(1); //首次入栈
            p = p->left;
        }

        if( !stk.empty() ){
            p = stk.top();
            flag = fs.top();

            if( p->right && flag==1 ){
                //第一次，不访问
                fs.pop();
                fs.push(2); //二次入栈
                p = p->right;
            }else{
                //第二次或无右子，访问
                func(p->data);
                stk.pop();
                fs.pop();
                p = nullptr;
            }
        }
    }
}

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
    _inOrder<int>( &node, [](int a){ cout << a << endl;} );

    cout << "-----------" << endl;
    cout << "前序遍历：" << endl;
    _preOrder<int>( &node, print );
    cout << "-----------" << endl;
    cout << "后序遍历" << endl;
    _lastOrder<int> (&node, print);
    cout << "-----------" << endl;

    int arr[] = {1, 2, 3 ,4, 5, 6};
    binaryTree<int> tree = binaryTree<int>::buildByLevelOrder(arr , 6);
    _inOrder<int>( tree.getRoot(), print );

    cout << "-----------" << endl;
    tree.inOrder( print );

    return 0;
}