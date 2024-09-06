#include <bits/stdc++.h>
#include <cmath> 

// Функция для перестановки элементов для сортировки вставками
void insertion_sort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Функция для создания кучи (heapify)
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;   // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1;  // левый потомок
    int right = 2 * i + 2; // правый потомок

    // Если левый потомок больше корня
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Если правый потомок больше, чем наибольший элемент на данный момент
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Если наибольший элемент не корень
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Рекурсивно heapify поддерево
        heapify(arr, n, largest);
    }
}

// Функция для сортировки кучей (Heap Sort)
void heap_sort(std::vector<int>& arr, int n) {
    // Построение кучи (перегруппировка массива)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        // Вызываем heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

// Функция для разделения (partition) в быстрой сортировке
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // выбираем последний элемент как опорный
    int i = low - 1; // индекс меньшего элемента

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Функция быстрой сортировки (Quick Sort)
void quick_sort(std::vector<int>& arr, int low, int high, int depth_limit) {
    while (high - low > 16) {
        if (depth_limit == 0) {
            // Переходим на сортировку кучей, если превышен лимит глубины рекурсии
            heap_sort(arr, high - low + 1);
            return;
        }
        --depth_limit;

        int pivot = partition(arr, low, high);
        if (pivot - low < high - pivot) {
            quick_sort(arr, low, pivot - 1, depth_limit);
            low = pivot + 1;
        } else {
            quick_sort(arr, pivot + 1, high, depth_limit);
            high = pivot - 1;
        }
    }
}

// Функция Introsort
void introsort(std::vector<int>& arr, int left, int right) {
    int depth_limit = 2 * std::log(right - left + 1); // Максимальная глубина рекурсии
    quick_sort(arr, left, right, depth_limit);   // Начинаем с быстрой сортировки
    insertion_sort(arr, left, right);            // Для малых подмассивов используем сортировку вставками
}

int main() {
    std::vector<int> arr;
    int n;

    std::cout << "Введите количество элементов: ";
    std::cin >> n;

    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        int elem;
        std::cin >> elem;
        arr.push_back(elem);
    }

    introsort(arr, 0, n - 1);

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
