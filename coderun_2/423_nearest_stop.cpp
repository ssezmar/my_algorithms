#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> stops(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> stops[i];
    }
    
    for (int i = 0; i < k; ++i) {
        long long x;
        cin >> x;
        
        // Найти первую остановку, которая не меньше x
        auto it = lower_bound(stops.begin(), stops.end(), x);
        
        if (it != stops.end() && *it == x) {
            // Если есть остановка с координатой, совпадающей с x, вывести её индекс
            cout << (it - stops.begin() + 1) << endl;
        } else {
            // Определить кандидатов для ближайших остановок слева и справа
            int right = (it == stops.end()) ? -1 : (it - stops.begin());
            int left = (it == stops.begin()) ? -1 : (it - stops.begin() - 1);
            
            if (left == -1) {
                // Нет остановок слева, берем ближайшую справа
                cout << right + 1 << endl;
            } else if (right == -1) {
                // Нет остановок справа, берем ближайшую слева
                cout << left + 1 << endl;
            } else {
                // Сравниваем расстояния до ближайших слева и справа остановок
                if (x - stops[left] <= stops[right] - x) {
                    cout << left + 1 << endl;
                } else {
                    cout << right + 1 << endl;
                }
            }
        }
    }
    
    return 0;
}
