#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

using namespace std;

void MaxSum(const vector<int>& v, int& sum, int start, int end) {
    vector<int> max3 = {0, 0, 0};

    for (int i = start; i < end; ++i) {
        if (v[i] > max3[0]) {
            max3[2] = max3[1];
            max3[1] = max3[0];
            max3[0] = v[i];
        } else if (v[i] > max3[1]) {
            max3[2] = max3[1];
            max3[1] = v[i];
        } else if (v[i] > max3[2]) {
            max3[2] = v[i];
        }
    }

    sum = max3[0] + max3[1] + max3[2];
}

int main() {
    const int size = 10000;
    vector<int> v(size);

    generate(v.begin(), v.end(), []() { return rand() % 100; });

    int sum1, sum2;
    thread t1(MaxSum, ref(v), ref(sum1), 0, size / 2);
    thread t2(MaxSum, ref(v), ref(sum2), size / 2, size);

    t1.join();
    t2.join();

    cout << sum1 + sum2 << endl;

    return 0;
}