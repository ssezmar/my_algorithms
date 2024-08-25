#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

int main() {

    std::string input;
    std::getline(std::cin, input); // Читаем всю строку

    std::istringstream iss(input); // Создаем поток для разбора строки
    std::string word;
    std::vector<std::string> words; // Вектор для хранения слов

    while (iss >> word) {
        words.push_back(word); // Добавляем каждое слово в вектор
    }

    std::map<std::string, int> mp;

    for(int i = 0; i < words.size(); i++){

        //std::cout << words[i] << std::endl;

        for(int j = 1; j < words[i].size(); j++) {
            std::string substring;
            substring.push_back(words[i][j-1]);
            substring.push_back(words[i][j]);
            //std::cout << substring << std::endl;
            if(mp.find(substring) != mp.end()) {
                mp[substring]++;
                
            } else {
                mp.insert(std::make_pair(substring, 1));
            }
        }
    }
    //  for (const auto& pair : mp) {
    //     std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    // }

    // Итератор для хранения пары с максимальным вторым значением
    auto maxPair = mp.begin();

    // Перебираем все элементы карты
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (it->second >= maxPair->second) {
            maxPair = it;
        }
    }
    std::cout << maxPair->first;
    return 0;
}