#include<iostream>
#include<unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> window;
    int r =0;
    int l=0;
    int longest = 0;

    for(int i=0; i<s.size();  i++) {
        auto it = window.find(s[i]);

        if(it != window.end()) {
            for(int j=r; j<window[s[i]]; j++) window.erase(s[j]);
            r=window[s[i]]+1;
            window[s[i]] = i;
        } else {
            window.insert(make_pair(s[i], i));
        }
        l++;

        if((l-r) >= longest) {
            longest = (l-r);
        }
    }
    cout<<l<<"  "<<r<<endl;
    return longest;
}

int main() {
    cout<<lengthOfLongestSubstring("pwwkew");
    return 0;
}