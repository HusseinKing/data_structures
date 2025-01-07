#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin>>t;

    ll n,g;
    cin>>n>>g;

    vector<vector<ll>> land;
    vector<ll> intersection(n);

    for(int j=0; j<n; j++) {
        for(int i=0; i<4; i++) {
            cin>>intersection[i];
        }
        land.push_back(intersection);
    }

    
}