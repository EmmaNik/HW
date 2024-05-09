#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Сортировка пузырьком
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// Сортировка выбором
void selectionSort(vector<int>& container, int left, int right) {
    if (left >= right) {
        return;
    }

    int min_index = left;
    for (int i = left + 1; i <= right; ++i) {
        if (container[i] < container[min_index]) {
            min_index = i;
        }
    }
    swap(container[left], container[min_index]);

    selectionSort(container, left + 1, right);
}

int main() {
    const int size = 10000;
    vector<int> numbers(size);

    for (int i = 0; i < size; ++i) {
        numbers[i] = getRandomNumber(1, 10000);
    }

    // Время сортировки пузырьком
    auto startBubbleSort = chrono::steady_clock::now();
    bubbleSort(numbers);
    auto endBubbleSort = chrono::steady_clock::now();
    chrono::duration<double> elapsedBubbleSort = endBubbleSort - startBubbleSort;

    // Время сортировки выбором
    auto startselectionSort = chrono::steady_clock::now();
    selectionSort(numbers, 0, size - 1);
    auto endselectionSort = chrono::steady_clock::now();
    chrono::duration<double> elapsedselectionSort = endselectionSort - startselectionSort;

    if (elapsedBubbleSort < elapsedselectionSort) {
        cout << "Сортировка пузырьком быстрее. Время: " << elapsedBubbleSort.count() << " секунд" << endl;
    } else {
        cout << "Сортировка выбором быстрее. Время: " << elapsedselectionSort.count() << " секунд" << endl;
    }

    return 0;
}