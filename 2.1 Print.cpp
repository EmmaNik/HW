#include <iostream>
#include <vector>

using namespace std;

template <typename T> void Print(const T& container, const string& delimiter) {
  for (const auto& element : container) {
    cout << element << delimiter;
  }
  cout << endl;
}

int main() {
  vector<int> data = {1, 2, 3};
  Print(data, ", ");  // 1, 2, 3
}