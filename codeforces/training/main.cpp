#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    
    while (t--) {
        int n;
        cin >> n;
        vector<char> current_vowels = vowels;  // Текущая перестановка гласных

        for (int i = 0; i < n; ++i) {
            // Выводим символ из текущей перестановки
            cout << current_vowels[i % 5];

            if (i > 0 && (i + 1) % 10 == 0) {
                // Генерируем следующую перестановку
                next_permutation(current_vowels.begin(), current_vowels.end());
            }
            // Каждые 25 символов обновляем перестановку
            if (i > 0 && (i + 1) % 5 == 0) {
                // Генерируем следующую перестановку
                reverse(current_vowels.begin(), current_vowels.end());
            }
        }
        cout << endl;
    }
    
    return 0;
}
