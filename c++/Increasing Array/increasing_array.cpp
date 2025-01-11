#include<iostream>
#include<vector>

typedef long long ll;

int main() {
    int n;
    std::cin>>n;
    std::vector<ll> nums(n);

    for(int i=0; i<n; i++) std::cin>>nums[i];

    ll count = 0;

    for(int j=1; j<n; j++) {
        if (nums[j] >= nums[j-1]) continue;
        ll diff = nums[j-1] - nums[j];
        count += diff;
        nums[j] += diff;
    }

    std::cout<< count<<std::endl;

    return 0;
}
