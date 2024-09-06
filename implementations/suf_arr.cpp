#include <bits/stdc++.h>
#include <algorithm>

std::vector<int> build_suffix_array(const std::string &s) {
    int n = s.size();
    std::vector<int> suffix_array(n), rank(n), temp(n), cnt(std::max(256, n), 0);

    // Инициализация: сортируем по первым символам (сортировка подсчётом)
    for (int i = 0; i < n; i++) {
        rank[i] = s[i];
        suffix_array[i] = i;
    }

    // Постепенно увеличиваем длину обрабатываемых префиксов
    for (int k = 1; k < n; k *= 2) {
        auto cmp = [&](int a, int b) {
            if (rank[a] != rank[b]) return rank[a] < rank[b];
            int ra = (a + k < n) ? rank[a + k] : -1;
            int rb = (b + k < n) ? rank[b + k] : -1;
            return ra < rb;
        };

        // Сортировка пар по первому и второму ключу (линейно)
        std::sort(suffix_array.begin(), suffix_array.end(), cmp);

        // Пересчитываем ранги
        temp[suffix_array[0]] = 0;
        for (int i = 1; i < n; i++) {
            temp[suffix_array[i]] = temp[suffix_array[i - 1]] + (cmp(suffix_array[i - 1], suffix_array[i]) ? 1 : 0);
        }
        rank = temp;
    }

    return suffix_array;
}

// Функция для вывода суффиксного массива
void print_suffix_array(const std::string &s, const std::vector<int> &suffix_array) {
    for (int i = 0; i < suffix_array.size(); i++) {
        std::cout << i << ": " << suffix_array[i] << " - " << s.substr(suffix_array[i]) << std::endl;
    }
}

int main() {
    std::string s;
    std::cout << "Введите строку: ";
    std::cin >> s;

    s += '$';  // Добавляем специальный символ в конец строки для корректного сравнения
    std::vector<int> suffix_array = build_suffix_array(s);

    std::cout << "Суффиксный массив:" << std::endl;
    print_suffix_array(s, suffix_array);

    return 0;
}
