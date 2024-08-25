#include <iostream>
#include <vector>


struct DSU {
    std::vector<int> sz, par;

    DSU(int n) 
        :sz(n+1, 1)
        , par(n+1)
    {
        for(int i = 1; i <= n; i++) {
            par[i] = i;
        }
    }

     bool isConnected(int u, int v) {
        return getPar(u) == getPar(v);
     }

     int getPar(int u) {
        return (u == par[u] ? u: par[u] = getPar(par[u]));;
     }

    void connect(int u, int v) {
        u = getPar(u), v = getPar(v);
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
    int n, m; std::cin >> n >> m;

    DSU dsu(n);

    while(m --> 0) {
        std::string s; std::cin >> s;
        int u, v; std::cin >> u >> v;
        if(s[0] == 'u') {
            dsu.connect(u, v);
        } else {
            std::cout << (dsu.isConnected(u, v) ? "YES\n" : "NO\n");
        }
    }
}