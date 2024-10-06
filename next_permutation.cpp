#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i, j;
    
    // Step 1: Find the first decreasing element from the end
    for(i = n - 2; i >= 0; i--) {
        if(nums[i] < nums[i + 1]) break;
    }

    // If no such element is found, the array is in descending order
    if(i < 0) { 
        sort(nums.begin(), nums.end());
        return;
    }

    // Step 2: Find the smallest element larger than nums[i] from the right end
    int ind = i + 1;
    for(j = i + 1; j < n; j++) {
        if(nums[j] > nums[i] && nums[j] <= nums[ind]) {
            ind = j;
        }
    }

    // Step 3: Swap nums[i] and nums[ind]
    swap(nums[i], nums[ind]);

    // Step 4: Sort the part of the array after index i
    sort(nums.begin() + i + 1, nums.end());
}

int main() {
    // Input: A vector of integers
    vector<int> nums;

    cout << "Enter the number of elements in the array: ";
    int n;
    cin >> n;

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    // Call the nextPermutation function to compute the next permutation
    nextPermutation(nums);

    // Output the result
    cout << "Next permutation is: ";
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
