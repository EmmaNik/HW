#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

string mostoftenword(const string& text) {
    map<string, int> wordCount;

    istringstream iss(text);
    string word;
    while (iss >> word) {
        wordCount[word]++;
    }

    int maxCount = 0;
    string mostoftenword;
    for (const auto& pair : wordCount) {
        if (pair.second > maxCount || (pair.second == maxCount && pair.first < mostoftenword)) {
            maxCount = pair.second;
            mostoftenword = pair.first;
        }
    }

    return mostoftenword;
}

int main() {
    string text = "один один два три четыре три два два";
    string mostoften = mostoftenword(text);
    cout << "Слово, встречающееся чаще всего, - " << mostoften << endl;
    return 0;
}