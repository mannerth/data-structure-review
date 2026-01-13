/**
 * https://www.luogu.com.cn/problem/P4779
 * 
 */
#include<iostream>
#include<vector>
using namespace std;
const int N = 1e3+1;
int a[N][N];
int n, m, s;

int distanceFromS[N];
bool vis[N];
vector<int> newReachable;

int main(){
    for(int i =1; i <= n; ++i){
        vis[i] = false;
        for(int j = 1; j <= n;++j){
            a[i][j] = -1;
        }
    }
        

    cin >> n >> m >> s;
    int x, y, w;
    while(m--){
        cin >> x >> y >> w;
        a[x][y] = w;
    }

    vis[s] = true;

    for(int i = 1; i <= n; ++i){
        a[i][i] = 0;
        if( a[s][i]!= -1 ){
            distanceFromS[i] = a[s][i];
            newReachable.push_back(i);
            vis[i] = true;
        }else{
            distanceFromS[i] = -1;
        }
    }

    while(!newReachable.empty()){

        int min = newReachable[0];
        std::vector<int>::iterator idx;
        for(auto i = newReachable.begin(); i!=newReachable.end(); ++i){
            if( distanceFromS[*i]!=-1 && distanceFromS[*i]<distanceFromS[min] ){
                min = *i;
                idx = i;
            }
        }
        newReachable.erase(idx);

        for(int i = 1; i <= n; ++i){
            if( !vis[i] && a[min][i]!=-1 ){
                newReachable.push_back(i);
                if(distanceFromS[i]==-1 || distanceFromS[min]+a[min][i]<distanceFromS[i]){
                    distanceFromS[i] = distanceFromS[min]+a[min][i];
                }
            }
        }
    }

    for(int i = 1; i<= n; ++i){
        cout << distanceFromS[i] << " ";
    }

    return 0;
}