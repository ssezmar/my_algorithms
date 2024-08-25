#include <bits/stdc++.h>

struct DSU{
    std::vector<int> sz, par;
    DSU(int n) : sz(n+1, 1), par(n+1) {
        for(int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }

    int getPar(int u) {
        return (u == par[u] ? u : par[u] = getPar(par[u]));
    }

    bool isConnected(int u, int v) {
        return getPar(u) == getPar(v);
    }

    void connect(int u, int v) {
        u = getPar(u); v = getPar(v);
        if(u == v) {
            return;
        }
        if(sz[u] < sz[v]) {
            std::swap(u, v);
        }
        sz[u] += sz[v];
        par[v] = u;
    }
};




int main() {

    int n, m, k; std::cin >> n >> m >> k;

    while(m --> 0) {
        int a, b; std::cin >> a >> b;
    }

    std::vector<std::pair<std::string, std::pair<int, int>>> tasks(k);
    for(int i = 0; i < k; i++) {
        std::string s; std::cin >> s;
        int u, v; std::cin >> u >> v;
        tasks[i] = std::make_pair(s, std::make_pair(u, v));
    }

    std::reverse(tasks.begin(), tasks.end());
    DSU dsu(n);

    std::vector<std::string> ans;

    for(int i = 0; i < k; i++) {
        std::string req = tasks[i].first;
        int u = tasks[i].second.first;
        int v = tasks[i].second.second;
        if(req == "ask") {
            ans.push_back(dsu.isConnected(u, v) ? "YES\n" : "NO\n");
        } else if(req == "cut") {
            dsu.connect(u, v);
        }
    }

    std::reverse(ans.begin(), ans.end());
    for(auto a : ans) {
        std::cout << a;
    }

    return 0;
}