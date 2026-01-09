#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int p[21], rnk[21], n;

int root( int x ){
    if(p[x]==x) return x;
    //路径压缩
    return p[x] = root(p[x]);
}

void merge( int x, int y ){
    int rootx = root(x);
    int rooty = root(y);

    if( rootx==rooty ) return;

    if( rnk[rootx] > rnk[rooty] ){
        p[rooty] = rootx;
    }else if( rnk[rootx] < rnk[rooty] ){
        p[rootx] = rooty;
    }else{
        p[rooty] = rootx;
        rnk[rootx]++;
    }
}

int main(){
    for(int i =1 ; i <= 21; ++i){ 
        p[i] = i;
        rnk[i] = 0;
    }

    cout << "Input" << endl;
    cin >> n;
    int t;
    cin >> t;
    while(t--){
        int x, y;
        char c1,c2,c3;
        cin >>c1>> x>>c2 >> y >> c3;
        merge( x, y);
    }

    unordered_map< int, vector<int> > map;
    for(int i = 1; i <= n; ++i){
        int r = root(i);
        if( map.find( r ) != map.end() ){
            map[r].push_back( i );
        }else{
            vector<int> v;
            v.push_back(i);
            map[r] = v;
        }
    }

    cout << "Output" << endl;
    for(unordered_map<int, vector<int>>::iterator it = map.begin(); it != map.end(); ++it) {
        vector<int>& v = it->second;
        sort(v.begin(), v.end());
        cout << "(";
        for(int i = 0; i < v.size(); ++i){
            cout << v[i];
            if( i != v.size()-1 ) cout << ",";
        }
        cout << ")" << endl;
    }

    cout << "End" << endl;

    return 0;
}