#include <iostream>
using namespace std;

int Sum(int n) {
    int sum = 0;
    while (n > 0) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

int happy(int n) {
    do {
        n = Sum(n); // Продвигаемся на следующее число
    } while (n != 1 && n != 4); // Цикл до тех пор, пока не встретим 1 (счастливое число) или 4 (цикл не содержащий 1)
    
    if (n == 1) {
        return 1; // Если число счастливое
    } else {
        return -1; // Иначе, число не счастливое
    }
}
  
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (happy(n) == 1) {
        cout << n << " счастливое число" << endl;
    } else {
        cout << n << " не является счастливым" << endl;
    }

    return 0;
}