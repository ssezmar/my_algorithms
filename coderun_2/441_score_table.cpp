#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> players(n);
    std::unordered_map<std::string, int> scoreMap;

    for (int i = 0; i < n; ++i) {
        std::cin >> players[i];
        scoreMap[players[i]] = 0; // Инициализация счётчика для каждого игрока
    }

    int m;
    std::cin >> m;
    std::string dummy;
    std::getline(std::cin, dummy);
    int a = 0;
    int b = 0;

    for (int i = 0; i < m; ++i) {
        std::string line;
        std::getline(std::cin, line);

        size_t colonPos = line.find(':');
        size_t spacePos = line.find(' ', colonPos);

        std::string playerName = line.substr(spacePos + 1);

        int pointsA = std::stoi(line.substr(0, colonPos));
        int pointsB = std::stoi(line.substr(colonPos + 1, spacePos - colonPos-1));
        // std::cout << colonPos << "\t" << spacePos << std::endl;
        // std::cout << "Points A: '" << pointsA << "' \n";  
        // std::cout << "Points B: '" << pointsB << "' \n";  

        scoreMap[playerName] += pointsA - a + pointsB - b;
        a = pointsA;
        b = pointsB;
    }


    std::string topPlayer;
    int maxScore = 0;

    for (const auto& entry : scoreMap) {
        if (entry.second > maxScore || (entry.second == maxScore && entry.first > topPlayer)) {
            topPlayer = entry.first;
            maxScore = entry.second;
        }
    }

    std::cout << topPlayer << " " << maxScore << std::endl;

    return 0;
}