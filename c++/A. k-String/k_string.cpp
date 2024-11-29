#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<char, int> freq;

    for (char& i: s) {
        auto letter = freq.find(i);

        if (letter != freq.end()) {
            freq[i] += 1;
        } else {
            freq[i] = 1;
        }
    }

    vector<char> fin;
    for (auto& letter: freq) {
        if (letter.second % n != 0) {
            cout << "-1"<<endl;
            return 0;
        }
        for (int j=0; j<(letter.second/n); j++) {
            fin.push_back(letter.first);
        }
    }

    for (int i=0; i<n; i++) {
        for(char& j: fin) {
            cout<<j;
        }
    }
    cout <<endl;
    return 0;
}