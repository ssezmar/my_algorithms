#include <bits/stdc++.h>

void task1(int* arr)
{
    std::vector<int> marks(4);
    for(int i = 0; i < 10; i++) {
        marks[arr[i]-2]++;
    }
    for(int i = 0; i < 4; i++) {
        std::cout << "Mark " << i+2 << " : " << marks[i] << '\t';
    }
    std::cout << '\n';
}




int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    
    int* arr = new int(10);

    for(int i = 0; i < 10; i++) {
        std::cin >> arr[i];
    }
    task1(arr);


    return 0;
}