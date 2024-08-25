#include <iostream>
#include <vector>
#include <string>

bool check_winner(const std::vector<std::string>& board, int n, int m) {
    const int required_count = 5;
    // Направления: вправо, вниз, вниз вправо, вниз влево
    const int directions[4][2] = {
        {0, 1},  // горизонтально
        {1, 0},  // вертикально
        {1, 1},  // диагональ вниз вправо
        {1, -1}  // диагональ вниз влево
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == '.') continue; // Пропускаем пустые клетки
            char current = board[i][j];
            // Проверяем 4 направления
            for (auto dir : directions) {
                int count = 1;
                int x = i, y = j;
                for (int step = 1; step < required_count; ++step) {
                    x += dir[0];
                    y += dir[1];
                    if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == current) {
                        count++;
                    } else {
                        break;
                    }
                }
                if (count == required_count) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> board(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> board[i];
    }

    if (check_winner(board, n, m)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}