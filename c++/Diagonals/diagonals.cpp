#include<iostream>
#include<cmath>

using namespace std;

int sub_sol(int n, int k, int& used) {
    if(k==0) {
        return 0;
    }
    if (k < (n*(n+1)/2)) {
        int var = (n*(n+1)/2) - k;
        double res = ((-1 + sqrt(1+(8*var)))/2);
        return n - int(floor(res)) + used;
    } else {
        return n + used;
    }
}

int solve(int n,  int k, int& used) {
    int distr = 0;
    if (k>n) {
        distr = k-n;
        used++;
    } else if(k==0) {
        return 0;
    } else {
        return 1;
    }

    int sub_used = 0;
    return used + sub_sol(2*n-2, distr, sub_used);
}

int main() {
//    int t;
//    cin>>t;
//    int n, k;
//
//    while(t>0) {
//        cin>>n>>k;
//        int used = 0;
//        cout<<solve(n, k, used)<<endl;
//        t--;
//    }
    int used = 0;
    cout<<solve(2, 4, used)<<endl;
    return 0;
}