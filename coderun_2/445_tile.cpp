#include <iostream>

int main() {

    int b, w;
    std::cin >> b >> w;


    int s = (b - 4) / 2;

    for(int m = 1; m <= s - 1; m++) {
        if((s - m) * (m) == w) {
            std::cout << s - m + 2 << " " << m + 2;
            return 0;
        }
    }


    return 0;
}