#include<iostream>
#include<cmath>
using namespace std;


int const N = 1e4+1;
int n, m;   //问题参数
int p[N];   //元素i的父节点
int rnk[N]; //等价类的秩

/// 带路径压缩的求根节点
int root(int x){
    if(p[x]==x)return x;
    return p[x] = root(p[x]);
}

/// 按秩合并
void merge(int x, int y){
    x = root(x), y = root(y);
    if(rnk[x]>rnk[y])swap(x,y);
    p[x] = y;
    if(rnk[x]==rnk[y])rnk[y]++;
}

int main(){
    int op,x,y;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        p[i] = i;
    }
    while(m--){
        cin >> op >> x >> y;
        switch(op){
            case 2:
                if(root(x)==root(y))cout << "Y" << "\n";
                else cout << "N" << "\n";
                break;
            case 1:
                merge(x, y);
                break;
        }
    }
    return 0;
}
