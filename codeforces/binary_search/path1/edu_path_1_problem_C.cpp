#include <bits/stdc++.h>

int binary_search(const std::vector<int>& v, int target) {
    int res = v.size();
    int r = v.size()-1;
    int l = 0;
    while(l <= r) {
        int m = l + (r - l) / 2;

        if(v[m] >= target) {
            r = m - 1;
            res = std::min(res, m);
        } else if(v[m] < target) {
            
            l = m + 1;
        }
    }

    return res + 1;
}



int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, k; std::cin >> n >> k;
    std::vector<int> v(n);
    for(int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    for(int i = 0; i < k; i++) {
        int target; std::cin >> target;
        int ans = binary_search(v, target);
        std::cout << ans << '\n';
    }

    return 0;
}