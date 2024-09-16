#include <bits/stdc++.h>

long long w, h, n;

bool good(long long a) {
    return (a/w)*(a/h) >= n;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cout.tie(nullptr);
    std::cin >> w >> h >> n;

    long long r = 1;
    long long l = 0;

    while(!good(r)) {
        r *= 2;
    }

    while(l+1 < r) {
        long long m = (l+r)/2;

        if(good(m)) {
            r = m;
        } else {
            l = m;
        }
    }

    std::cout << r;
    return 0;
}