#include <iostream>
#include <string>
#include <vector>

int main() 
{
	
    int a, b, n;
    std::cin >> a >> b >> n;

    if(a > ((b + n)- 1) / n) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }

	return 0;
}