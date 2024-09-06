#include <bits/stdc++.h>

class SegmentTree {
private:
    std::vector<int> tree;  // Сегментное дерево
    int n;

    // Построение дерева (инициализация)
    void build(const std::vector<int>& data, int node, int start, int end) {
        if (start == end) {
            // Лист дерева
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            int left_child = 2 * node + 1;
            int right_child = 2 * node + 2;
            // Рекурсивно строим дерево для потомков
            build(data, left_child, start, mid);
            build(data, right_child, mid + 1, end);
            // Внутренний узел — это сумма его детей
            tree[node] = tree[left_child] + tree[right_child];
        }
    }

    // Обновление элемента массива
    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            // Лист дерева, обновляем значение
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            int left_child = 2 * node + 1;
            int right_child = 2 * node + 2;
            // Обновляем нужного ребенка
            if (idx <= mid) {
                update(left_child, start, mid, idx, value);
            } else {
                update(right_child, mid + 1, end, idx, value);
            }
            // Обновляем значение текущего узла после обновления ребенка
            tree[node] = tree[left_child] + tree[right_child];
        }
    }

    // Запрос суммы на отрезке
    int query(int node, int start, int end, int L, int R) {
        if (R < start || L > end) {
            // Отрезок вне диапазона запроса
            return 0;
        }
        if (L <= start && end <= R) {
            // Отрезок полностью внутри диапазона запроса
            return tree[node];
        }
        // Часть отрезка попадает в запрос
        int mid = (start + end) / 2;
        int left_child = 2 * node + 1;
        int right_child = 2 * node + 2;
        int sum_left = query(left_child, start, mid, L, R);
        int sum_right = query(right_child, mid + 1, end, L, R);
        return sum_left + sum_right;
    }

public:
    // Конструктор для инициализации дерева
    SegmentTree(const std::vector<int>& data) {
        n = data.size();
        tree.resize(4 * n);  // Выделяем память
        build(data, 0, 0, n - 1);
    }

    // Обновление элемента массива
    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }

    // Запрос суммы на отрезке [L, R]
    int query(int L, int R) {
        return query(0, 0, n - 1, L, R);
    }
};