#include <bits/stdc++.h>

bool binary_search(const std::vector<int> v, const int& target) {
    int l, r;
    l = 0; 
    r = v.size()-1;
    
    while(l <= r) {
        int m = l + (r - l) / 2;

        if(v[m] == target) {
            return true;
        } else if(v[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return false;    
}

void solve() {
    int n, k; std::cin >> n >> k;
    std::vector<int> v(n);
    for(int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    for(int i = 0; i < k; i++) {
        int q; std::cin >> q;
        std::cout << (binary_search(v, q) ? "YES\n" : "NO\n");
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    solve();
    return 0;
}