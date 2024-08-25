#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

string convertToBasicForm(string  s) {
    int counter = 0;
    string res;
    res.push_back(s[0]);

    for(int i = 1; i < s.size(); i++) {
        if(res[counter] != s[i]) {
            res.push_back(s[i]);
            counter++;
        }
    }



    return res;
}


vector<double> letterCounter(string s) {
    vector<double> res;
    
    char now = s[0];
    int counter = 1;
    for(int i = 1; i < s.size(); i++){
        if(s[i] != now) {
            res.push_back(counter);
            now = s[i];
            counter = 1;
        } else {
            counter++;
        }
    }
    res.push_back(counter);

    return res;
}



int main() {

    vector<string> strs;
    for(int i = 0; i < 3; i++){
        string s;
        cin >> s;
        strs.push_back(s);
    }

    if(convertToBasicForm(strs[0]) != convertToBasicForm(strs[1]) || 
    convertToBasicForm(strs[1]) != convertToBasicForm(strs[2])) {
        cout << "IMPOSSIBLE";
        return 0;
    } else {
        string basicForm = convertToBasicForm(strs[0]);
        // cout << "basic from: " << basicForm << endl;
        vector<double> normalizeNums;
        vector<vector<double>> counts;

        for(int i = 0; i < 3; i++) {
            counts.push_back(letterCounter(strs[i]));
        }
        

        // for(int j = 0; j < 3; j++) {
        //     cout << "let nums " << j ;
        //     for(int i = 0; i < counts[j].size(); i++) {
        //         cout << counts[j][i] << " ";
        //     }
        //     cout << endl;
        // }

        for(int i = 0; i < counts[0].size(); i++) {

            int a = counts[0][i];
            int b = counts[1][i];
            int c = counts[2][i];
            std::vector<int> n = {a, b, c};
            std::sort(n.begin(), n.end());
            normalizeNums.push_back(n[1]);
        }

        // cout << "norm nusm: ";
        // for(int i = 0; i < normalizeNums.size(); i++) {
        //     cout << normalizeNums[i] << " ";
        // }
        // cout << endl;

        string res;
        for(int i = 0; i < normalizeNums.size(); i++){
            for(int j = 0; j < normalizeNums[i]; j++) {
                res.push_back(basicForm[i]);
            }
        }

        cout << res;
    }
    return 0;
}