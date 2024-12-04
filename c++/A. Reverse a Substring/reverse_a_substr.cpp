#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    pair<char, int> h = make_pair(s[0], 0);
    pair<char, int> l;
    bool found = false;

    for (int i=1; i<n; i++) {
        if (s[i] < h.first) {
            l = make_pair(s[i], i);
            found = true;
            break;
        } else {
            h = make_pair(s[i], i);
        }
    }

    if (!found) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl << h.second + 1<<" "<< l.second + 1 << endl;
    }
    return 0;
}