#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

class graph{
    vector< vector<int> > data;
    int n, m;
public:
    graph(int n, int m): data(n+1, vector<int>(n+1, 0) ){
        this->n = n;
        this->m = m;
    }

    void add_edge(int x, int y, int weight){
        data[x][y] = weight;
        data[y][x] = weight;
    }

    vector<int> get_ads(int x){
        vector<int> res;
        for(int i = 1; i <= n; ++i){
            if( data[x][i] ){
                res.push_back(i);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }

    void bfs(){
        queue<int> q;
        int* vis = new int[n+1];
        for(int i = 1; i <= n; ++i) vis[i] = 0;
        int cnt = 1;
        q.push(1);
        vis[1] = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if( cnt==1 ){
                cout << cur;
                cnt++;
            }else{
                cnt++;
                cout << "," << cur ;
            }

            vector<int> ads = get_ads(cur);
            for(int i = 0; i < ads.size(); ++i){
                if( !vis[ads[i]] ){
                    q.push(ads[i]);
                    vis[ads[i]] = 1;
                }
            }

        }
        cout << endl;
        delete[] vis;
    }

    void dfs(){
        int *vis = new int[n+1];
        for(int i = 1; i <= n; ++i) vis[i] = 0;
        vis[1] = 1;
        dfs_r(1,1,vis);
        cout << endl;
        delete[] vis;
    }

    void dfs_r(int p, int cnt, int *vis){
        if(cnt==1){
            cout << p;
        }else{
            cout << "," << p;
        }

        vector<int> ads = get_ads(p);
        for(int i = 0; i < ads.size(); ++i){
            if(!vis[ads[i]]){
                vis[ads[i]] = 1;
                dfs_r(ads[i], cnt+1, vis);
            }
        }
    }

    int short_path(int x, int y){
        vector<int> dist(n+1, INT_MAX);
        dist[x] = 0;
        priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
        pq.push( make_pair(0, x) );
        while(!pq.empty()){
            pair<int,int> cur = pq.top();
            pq.pop();
            int u = cur.second;
            int d = cur.first;
            if(d > dist[u]) continue;
            for(int v = 1; v <= n; ++v){
                if(data[u][v]){
                    int w = data[u][v];
                    if(dist[u] + w < dist[v]){
                        dist[v] = dist[u] + w;
                        pq.push( make_pair(dist[v], v) );
                    }
                }
            }
        }
        return dist[y];
    }
};

int main(){
    char c;
    cout << "Input" << endl;
    int m, n;
    cin >> n >> c >> m;
    graph g(n, m);
    for(int i = 1; i <= m; ++i){
        int x, y, w;
        cin >> x >> c >> y >> c >> w;
        g.add_edge(x, y, w);
    }

    cout << "output" << endl;
    g.bfs();
    g.dfs();
    cout << (g.short_path(1, n) == INT_MAX ? 0 : g.short_path(1, n)) << endl;
    cout << "end" << endl;
    return 0;
}