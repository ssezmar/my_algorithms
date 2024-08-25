#include <bits/stdc++.h>

struct DSU {
    
    std::vector<int> sz, par, min, max;
    
    DSU(int n)
        : sz(n+1, 1)
        , par(n+1)
        , min(n+1)
        , max(n+1)
    {
        for (int i = 1; i <= n; i++)
            min[i] = max[i] = par[i] = i;
    }
    
    bool isConnected(int u, int v) {
        return getPar(u) == getPar(v);
    }
    
    int getPar(int u) {
        return (u == par[u] ? u : par[u] = getPar(par[u]));
    }
    
    void connect(int u, int v) {
        u = getPar(u), v = getPar(v);
        if (u == v)
            return;
        if (sz[u] < sz[v])
            std::swap(u, v);
        // присоединять "v" к "u"
        sz[u] += sz[v];
        par[v] = u;
        min[u] = std::min(min[u], min[v]);
        max[u] = std::max(max[u], max[v]);
    }

    void getInfo(int u) {
        u = getPar(u);
        std::cout << min[u] << ' ' << max[u] << ' ' << sz[u] << '\n';
    }
    
};

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);


    int n, m; std::cin >> n >> m;

    DSU dsu(n);

    while(m --> 0) {
        std::string s; std::cin >> s;
        if(s[0] == 'u') {
            int v, u; std::cin >> u >> v;
            dsu.connect(u, v);
        } else if(s[0] == 'g'){
            int u; std::cin >> u;
            dsu.getInfo(u);
        }

    }   

    return 0;
}