#include <bits/stdc++.h>

/* Classical realization of disjoint set union
    Methods: int getPar(int) return parent of node,
    bool isConnected(int u, int v) return is connected u and v
    void connect(int u, int v) connect node u with node v

    Using path compression heuristic.
*/

struct DSU {
    std::vector<int> par, sz;
        
    DSU(int n) : par(n+1), sz(n+1, 1) {
        for(int i = 0; i <= n; i++) {
            sz[i] = i;
        }
    }

    int getPar(int u) {
        return (u == par[u] ? u : par[u] = getPar(par[u]));
    }

    bool isConnected(int u, int v) {
        return getPar(u) == getPar(v);
    }

    void connect(int u, int v) {
        u = getPar(u);
        v = getPar(v);

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