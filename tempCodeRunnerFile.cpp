#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MAX 100005
#define INF 1000000000

vector<pii> adj[MAX], radj[MAX];
int dist[MAX], rdist[MAX];

void bidirectional_search(int s, int t) {
    priority_queue<pii, vector<pii>, greater<pii>> pq, rpq;
    pq.push(mp(0, s));
    rpq.push(mp(0, t));
    dist[s] = 0;
    rdist[t] = 0;
    while(!pq.empty() && !rpq.empty()) {
        int u = pq.top().S;
        pq.pop();
        for(auto v : adj[u]) {
            if(dist[v.F] > dist[u] + v.S) {
                dist[v.F] = dist[u] + v.S;
                pq.push(mp(dist[v.F], v.F));
            }
        }
        if(dist[u] + rdist[u] >= dist[t]) {
            break;
        }
        int ru = rpq.top().S;
        rpq.pop();
        for(auto rv : radj[ru]) {
            if(rdist[rv.F] > rdist[ru] + rv.S) {
                rdist[rv.F] = rdist[ru] + rv.S;
                rpq.push(mp(rdist[rv.F], rv.F));
            }
        }
        if(dist[ru] + rdist[ru] >= dist[t]) {
            break;
        }
    }
    int ans = INF;
    for(int i = 1; i <= t; i++) {
        ans = min(ans, dist[i] + rdist[i]);
    }
    cout << "Minimum cost from " << s << " to " << t << " is = " << ans << endl;
}

int main() {
    int n, m, u, v, w, s, t;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
        radj[u].pb(mp(v, w));
        radj[v].pb(mp(u, w));
    }
    cin >> s >> t;
    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
        rdist[i] = INF;
    }
    bidirectional_search(s, t);
    return 0;
}