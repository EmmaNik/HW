#include <iostream>
#include <list>

using namespace std;

void Sort(const list<int>& original, list<int>& plus, list<int>& minus) {
    for (int num : original) {
        if (num >= 0)
            plus.push_back(num);
        else
            minus.push_back(num);
    }
    
    plus.sort();
    minus.sort();
}

int main() {
    list<int> original = {1, -2, 3, -6, 0, -12, -3};
    list<int> plus, minus;

    Sort(original, plus, minus);

    cout << "Положительные элементы:" << endl;
    for (int num : plus)
        cout << num << " ";
    cout << endl;

    cout << "Отрицательные элементы:" << endl;
    for (int num : minus)
        cout << num << " ";
    cout << endl;

    return 0;
}