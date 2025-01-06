#include <iostream>
#include <vector>

typedef long long ll;

int char_to_num(char& ch) {
    return static_cast<int>(ch)-97;
}

std::vector<ll> sol;
bool consecutive = false;
std::vector<ll> nums = {1,2,-3,4,-5,6};
int k = 1;

int solve(int step) {
    int count = 0;
    if(step == nums.size()) {
        if(sol.size() < k + 1) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (nums[step] < 0 || consecutive) {
            consecutive = false;
            count += solve(step+1);
        } else {
            sol.emplace_back(nums[step]);
            consecutive = true;
            count += solve(step+1);
            sol.pop_back();
            consecutive = false;
            count += solve(step+1);
        }
    }

    return count;
}

int main() {
    std::cout<<"answer: "<<solve(0);
    return 0;
}
