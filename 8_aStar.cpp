#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MAX 100005
#define INF 1000000000

vector<pii> adj[MAX];
int dist[MAX];
bool vis[MAX];

void a_star(int s, int t) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(mp(0, s));
    dist[s] = 0;
    while(!pq.empty()) {
        int u = pq.top().S;
        pq.pop();
        if(u == t) {
            break;
        }
        if(vis[u]) {
            continue;
        }
        vis[u] = true;
        for(auto v : adj[u]) {
            if(dist[v.F] > dist[u] + v.S) {
                dist[v.F] = dist[u] + v.S;
                pq.push(mp(dist[v.F] + abs(v.F - t), v.F));
            }
        }
    }
    cout << "Minimum cost from " << s << " to " << t << " is = " << dist[t] << endl;
}

int main() {
    int n, m, u, v, w, s, t;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }
    cin >> s >> t;
    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
        vis[i] = false;
    }
    a_star(s, t);
    return 0;
}