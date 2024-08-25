#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main( ) {

    std::vector<int> nums(4);
    std::cin >> nums[0] >> nums[1] >> nums[2] >> nums[3];
    int res = 0;
    int sum = nums[0] + nums[1] + nums[2] + nums[3];


    if(sum < 2) {
        std::cout << 1;
        return 0;
    }
    if(sum <= 4) {
        std::cout << 0;
        return 0;
    }
    
    std::sort(nums.begin(), nums.end());

    if(nums[0] + nums[1] + nums[2] <= 4) {
        std::cout << 1;
        return 0;
    }
    else if(nums[0] + nums[1] <= 4) {
        std::cout << 2;
        return 0;
    }
    else if(nums[0] <= 4) {
        std::cout << 3;
        return 0;
    }
    else {
        std::cout << 4;
    }
    return 0;
}