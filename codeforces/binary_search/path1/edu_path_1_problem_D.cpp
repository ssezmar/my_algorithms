#include <bits/stdc++.h>
#include <algorithm>

int binary_search_min(const std::vector<int>& v, int target) {
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

int binary_search_max(const std::vector<int>& v, int target) {
    int res = -1;
    int r = v.size()-1;
    int l = 0;
    while(l <= r) {
        int m = l + (r - l) / 2;

        if(v[m] <= target) {
            res = std::max(res, m);
            l = m + 1;
        } else if(v[m] > target) {
            r = m - 1;
        }
    }

    return res + 1;
}




int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, k; std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end());
    std::cin >> k;
    for(int i = 0; i < k; i++) {
        int l, r; std::cin >> l >> r;
        std::cout << binary_search_max(v, r) - binary_search_min(v, l) + 1 << " ";    
    }
    

    return 0;
}