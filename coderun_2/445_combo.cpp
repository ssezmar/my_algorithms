#include <iostream>
#include <vector>
#include <map>
#include <climits>

// Функция для расчета стоимости покупок
int priceCalculation(
    std::map<int, int>& mp, // Карта товаров и их количества
    int countOfCombo,       // Количество комбо
    int comboCoast,         // Стоимость комбо
    std::vector<int>& combo,// Товары в комбо
    std::vector<int>& coasts) { // Стоимости товаров

    // Копируем карту товаров, чтобы не изменять оригинальную
    std::map<int, int> tempMap = mp;

    // Уменьшаем количество товаров в карте на количество купленных комбо
    for (int i = 0; i < combo.size(); i++) {
        if (tempMap.find(combo[i]) != tempMap.end()) {
            if (tempMap[combo[i]] - countOfCombo > 0) {
                tempMap[combo[i]] -= countOfCombo;
            } else {
                tempMap[combo[i]] = 0;
            }
        }
    }

    int res = 0;
    res += countOfCombo * comboCoast;

    // Считаем оставшиеся товары
    for (auto& product : tempMap) {
        res += coasts[product.first - 1] * product.second; // Исправлено: индексы начинаются с 0
    }

    return res;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> coasts(n);
    for (int i = 0; i < n; i++) {
        std::cin >> coasts[i];
    }

    int x;
    std::cin >> x;
    std::vector<int> combo(4);
    for (int i = 0; i < 4; i++) {
        std::cin >> combo[i];
    }

    int k;
    std::cin >> k;
    std::map<int, int> shoppingListMap;
    std::vector<int> shoppingList(k);
    for (int i = 0; i < k; i++) {
        std::cin >> shoppingList[i];
        shoppingListMap[shoppingList[i]]++;
    }

    // for (std::map<int, int>::iterator it = shoppingListMap.begin(); it != shoppingListMap.end(); ++it) {
    //     std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    // }

    // Подсчет минимальной цены
    int minCost = INT_MAX;
    for (int i = 0; i <= k; i++) { // Максимум возможных комбо - это k / 4
        int currentPrice = priceCalculation(shoppingListMap, i, x, combo, coasts);
        if (minCost > currentPrice) {
            minCost = currentPrice;
        }
    }
    std::cout << minCost << std::endl;

    return 0;
}