#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool sorting(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second != b.second)
        return a.second > b.second;  // Убывание стресса
    else
        return a.first < b.first;    // По возрастанию дедлайна
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> tasks(n);
    int maxDay = 0;

    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
        if (tasks[i].first > maxDay)
            maxDay = tasks[i].first;
    }

    // Сортировка задач по убыванию стресса и возрастанию дедлайна
    sort(tasks.begin(), tasks.end(), sorting);

    // Множество доступных дней
    set<int> availableDays;
    for (int i = 0; i <= maxDay; i++) {
        availableDays.insert(i);
    }

    long long total_stress = 0;

    for (const auto& task : tasks) {
        int deadline = task.first;
        int stress = task.second;

        auto it = availableDays.lower_bound(deadline);
        if (it != availableDays.begin()) {
            --it;
            availableDays.erase(it);  // Используем этот день
        } else {
            total_stress += stress;  // Не удалось найти подходящий день
        }
    }
    
    cout << total_stress << endl;

    return 0;
}