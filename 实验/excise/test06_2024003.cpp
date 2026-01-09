#include<iostream>
#include<queue>

using namespace std;

template<class T>
class treeNode{

    public:
    T val;
    treeNode* leftChild;
    treeNode* rightChild;

    public:
    treeNode(const T& v){
        val = v;
        leftChild = nullptr;
        rightChild = nullptr;
    }
    treeNode(const treeNode& ot){
        val = ot.val;
        leftChild = ot.leftChild;
        rightChild = ot.rightChild;
    }
    ~treeNode(){
        val.~T();
    }

};
int prtTp1, prtTp2;
int prtCnt1 = 0, prtCnt2 = 0;

void preOrder(const treeNode<char>* node){
    if(!node) return;
    cout << node->val ;
    prtCnt1++;
    if( prtCnt1%prtTp1 != 0){
        cout << ",";
    }else{
        cout << endl;
    }

    preOrder( node->leftChild );
    preOrder( node->rightChild );
}

void inOrder(const treeNode<char>* node){
    if(!node) return;
    inOrder( node->leftChild );
    cout << node->val ;
    prtCnt1++;
    if( prtCnt1%prtTp1 != 0){
        cout << ",";
    }else{
        cout << endl;
    }

    inOrder(node->rightChild);
}

void lastOrder(const treeNode<char>* node, int type = 1){
    if(!node) return;    
    lastOrder(node->leftChild, type);
    lastOrder(node->rightChild, type);
    cout << node->val ;
    if(type==1){    
        prtCnt1++;
        if( prtCnt1%prtTp1 != 0){
            cout << ",";
        }else{
            cout << endl;
        }
    }else{
        prtCnt2++;
        if( prtCnt2%prtTp2 != 0){
            cout << ",";
        }else{
            cout << endl;
        }
    }
}

template<class T>
int height(const treeNode<T>* node){
    int rh = 0;
    int lh = 0;
    if(node->leftChild) lh = height(node->leftChild);
    if(node->rightChild) rh = height(node->rightChild);
    return max(rh, lh)+1;
}

template<class T>
void level_order(treeNode<T>* node){
    if(!node) return;

    queue<treeNode<T>*> q;
    q.push(node);

    while(!q.empty()){
        treeNode<T>* p = q.front();
        q.pop();

        cout << p->val;
        prtCnt2++;
        if(prtCnt2%prtTp2 != 0){
            cout << ",";
        }else{
            cout << endl;
        }
        if(p->leftChild) q.push(p->leftChild);
        if(p->rightChild) q.push(p->rightChild);
    }
}

//abdec
//dbeac
treeNode<char>* buildTreeWithPreAndInOrder(string pres, string ins){
    if(pres.length()==0 && ins.length()==0){
        return nullptr;
    }

    if( pres.length()==1 && ins.length()==1){
        return new treeNode<char>(pres[0]);
    }

    treeNode<char>* t = new treeNode<char>(pres[0]);
    int position = ins.find(pres[0]);
    //左子树中序
    string left_str = ins.substr(0, position);
    //右子树中序
    string right_str = ins.substr( position+1 );
    
    int spl = -1;
    for(int i = 0; i < left_str.length(); ++i){
        spl = max( spl, (int) pres.find(left_str[i]) );
    }
    //左子树前序
    string l_p_s = pres.substr(1, spl);
    //右子树前序
    string r_p_s = pres.substr(spl+1);

    t->leftChild = buildTreeWithPreAndInOrder( l_p_s, left_str );
    t->rightChild = buildTreeWithPreAndInOrder( r_p_s, right_str );

    return t;
}

int main(){
    cout << "Input1"<< endl;
    string s;
    cin >> s;
    prtTp1 = s.length();
    cout << "Output1"<< endl;
    treeNode<char> r(s[0]);
    
    queue<treeNode<char>* > q;
    q.push(&r);

    for(int i = 1; i < s.length(); ++i){
        treeNode<char>* node = new treeNode<char>(s[i]);
        if( i%2 == 1){
            q.front()->leftChild = node;
        }else{
            q.front()->rightChild = node;
            q.pop();
        }
        q.push(node);
    }
    
    preOrder( &r );
    inOrder(&r);
    lastOrder(&r);
    cout << prtTp1 << endl;
    cout << height(&r) << endl;


    cout << "Input2" << endl;
    string pres, ins;
    cin >> pres >> ins;
    prtTp2 = ins.length();

    cout << "Output2" << endl;

    treeNode<char>* root = buildTreeWithPreAndInOrder(pres, ins);
    lastOrder(root, 2);
    level_order(root);

    cout << "End" << endl;
    return 0;
}

/**
 *          a
 *      b       c
 *   d    e
 * 
 */