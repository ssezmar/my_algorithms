#include <iostream>
#include <string>

using namespace std;

string increment_string_number(const string &num) {
    string result = num;
    long long n = result.size();
    bool carry = true;

    for (long long i = n - 1; i >= 0 && carry; --i) {
        if (result[i] == '9') {
            result[i] = '0';
        } else {
            result[i] += 1;
            carry = false;
        }
    }

    return result;
}

long long summer(string num, long long begin, long long end) {
    long long res = 0;
    for(long long i = begin; i < end; i++) {
        res += num[i] - '0';
    }
    return res;
}

void base_case(string& num, long long right_sum, long long left_sum) {
    long long n = num.size();
    long long difference = right_sum - left_sum;
    long long i = 0;
    while(1) {
        if (num[n-i-1] == '9'){
            i++;
        } else if (9 - (num[n-i-1] - '0') < difference) {
            difference -= 9 - (num[n-i-1] - '0');
            num[n-i-1] = '9';
            i++;
        } else {       
            num[n-i-1] += difference;
            i++;
            break;
        }
    }    
}


int main() {
    string num;
    cin >> num;
    // num = "";
    // for(int  i =0; i < 100000; i++) {
    //     num += "0";
    // }

    long long n = num.size();

    long long right_sum = summer(num, 0, n/2);
    long long left_sum = summer(num, n/2, n);

    if(right_sum == 0) {
        cout << string(n/2 - 1, '0')  + "1" + string(n/2 - 1, '0') + "1";
        return 0;
    }

    if(right_sum == left_sum) {
        if(right_sum / 9 == n / 2) {
            num = string(n/2 - 1, '0') + "1" + string(n/2 - 1, '0') + "1";
        } else {

            num = increment_string_number(num);
            right_sum = summer(num, 0, n/2);
            left_sum = summer(num, n/2, n);
        }
    }
    if(right_sum > left_sum) {
        base_case(num, right_sum, left_sum);
    } else if(right_sum < left_sum) {
        long long pos = 0;
        for(long long i = 1; i < n/2; i++){
            if (num[n-i-1] != '9') {
                num[n-i-1]++;
                pos = i;
                for(long long j = 0; j < i; j++) {
                    num[n-j-1] = '0';
                }
                right_sum = summer(num, 0, n/2);
                left_sum = summer(num, n/2, n);
                long long difference = right_sum - left_sum;
                if(difference < pos * 9  && right_sum > left_sum) {
                    base_case(num, right_sum, left_sum);
                    cout << num; 
                    return 0;
                }
                
            }
        }
        
        
        num = increment_string_number(num.substr(0, n/2)) + string(n/2, '0');
        right_sum = summer(num, 0, n/2);
        left_sum = summer(num, n/2, n);
        base_case(num, right_sum, left_sum);
    
        
    }
    right_sum = summer(num, 0, n/2);
    left_sum = summer(num, n/2, n);

    cout << num;
    return 0;
}