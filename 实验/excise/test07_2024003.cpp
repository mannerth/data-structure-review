#include<iostream>
using namespace std;

int a[30], n=0;

class node{
public:
    int data;
    node *left;
    node *right;
    node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int prtTp1;
int prtCnt1 = 0;

void preOrder(const node* node){
    if(!node) return;
    cout << node->data ;
    prtCnt1++;
    if( prtCnt1%prtTp1 != 0){
        cout << ",";
    }else{
        cout << endl;
    }

    preOrder( node->left );
    preOrder( node->right );
}

void inOrder(const node* node){
    if(!node) return;
    inOrder( node->left );
    cout << node->data ;
    prtCnt1++;
    if( prtCnt1%prtTp1 != 0){
        cout << ",";
    }else{
        cout << endl;
    }

    inOrder(node->right);
}

int main(){
    cout << "Input" << endl;
    for(int i = 1; i <= 20; ++i){
        cin >> a[++n];
        if(a[n] == 0){
            n--;
            break;
        }
    }
    cout << "Output" << endl;
    int *heap = new int[n+1];
    for(int i = 1; i <= n; ++i){
        heap[i] = a[i];
    }
    for(int i = n/2; i >= 1; --i){
        int temp = heap[i];
        int parent = i;
        int child = 2 * parent;
        while(child <= n){
            if(child < n && heap[child] < heap[child + 1]){
                child++;
            }
            if(temp >= heap[child]){
                break;
            }
            heap[parent] = heap[child];
            parent = child;
            child = 2 * parent;
        }
        heap[parent] = temp;
    }

    for(int i = 1; i <= n; ++i){
        cout << heap[i];
        if(i != n){
            cout << ",";
        }else{
            cout << endl;
        }
    }

    int reverse[30], h=0;
    int size = n;
    while(size){
        reverse[++h] = heap[1];

        int temp = heap[size];
        heap[size] = heap[1];
        size--;
        int parent = 1;
        int child = 2 * parent;
        while(child <= size){
            if(child < size && heap[child] < heap[child + 1]){
                child++;
            }
            if(temp >= heap[child]){
                break;
            }
            heap[parent] = heap[child];
            parent = child;
            child = 2 * parent;
        }
        heap[parent] = temp;
    }

    for(int i = n; i > 0; --i){
        cout << reverse[i];
        if(i != 1){
            cout << ",";
        }else{
            cout << endl;
        }
    }

    prtTp1 = n;
    node *root = new node(a[1]);
    for(int i = 2; i <= n; ++i){
        node *current = root;
        node *newNode = new node(a[i]);
        while(true){
            if(a[i] < current->data){
                if(current->left == nullptr){
                    current->left = newNode;
                    break;
                }else{
                    current = current->left;
                }
            }else if(a[i] > current->data){
                if(current->right == nullptr){
                    current->right = newNode;
                    break;
                }else{
                    current = current->right;
                }
            }else{
                prtTp1--;
                break;
            }
        }
    }

    
    prtCnt1 = 0;
    preOrder(root);
    inOrder(root);


    cout << "end" << endl;
    return 0;
}