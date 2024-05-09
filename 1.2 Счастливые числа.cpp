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
    int slow = n;
    int fast = n;

    do {
        slow = Sum(slow);
        fast = Sum(Sum(fast));
    } while (slow != fast);

    if (slow == 1) return 1;
    else return -1;
}
  
int main() {
  int n;
  cout << "Enter a number: ";
  cin >> n;

  if (happy(n) == 1) {
    cout << n << " is a happy number" << endl;
  } else {
    cout << n << " is not a happy number" << endl;
  }

  return 0;
}