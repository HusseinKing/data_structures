#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string word;
    cin >> word;

    vector<char> out;
    string olleh = "olleh";
    int index = 4;
    for(char& i: word) {
        if (i == olleh[index]) {
            index -= 1;
        }
        if (index < 0) {
            break;
        }
    }
    if (index > -1) {
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
    }
}