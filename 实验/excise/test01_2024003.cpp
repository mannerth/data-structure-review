#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

int a[30],n=0;
int vis[33];

void pOut(vector<int>* arr){
    for(int i = 0; i < arr->size(); ++i){
        cout << a[arr->at(i)];
        if(i!=arr->size()-1) cout << ",";
        else cout << endl;
    }
}

void r(vector<int>* store = new vector<int>){
    if(store->size()==n){
        pOut(store);
    }

    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            store->push_back(i);
            vis[i] = 1;
            r(store);
            store->pop_back();
            vis[i] = 0;
        }
    }

}

int main(){
    cout << "Input" << endl;
    while(cin >> a[++n]){
        vis[n] = 0;
        if(a[n]==0){
            break;
        }
    }
    n--;
    
    cout << "Output" << endl;
    r();
    cout << "End" << endl;
    return 0;
}