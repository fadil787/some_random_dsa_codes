#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For INT_MIN and INT_MAX

using namespace std;

// Function to find the median of two sorted arrays
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    
    // Ensure nums1 is the smaller array
    if (n1 > n2) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int begin = 0;
    int end = n1;

    while (begin <= end) {
        int i1 = (begin + end) / 2; // Partition index for nums1
        int i2 = ((n1 + n2 + 1) / 2) - i1; // Partition index for nums2

        // Left and right elements for partition in nums1
        int l1 = (i1 == 0) ? INT_MIN : nums1[i1 - 1];
        int r1 = (i1 == n1) ? INT_MAX : nums1[i1];

        // Left and right elements for partition in nums2
        int l2 = (i2 == 0) ? INT_MIN : nums2[i2 - 1];
        int r2 = (i2 == n2) ? INT_MAX : nums2[i2];

        // Check if we've found a valid partition
        if (l1 <= r2 && l2 <= r1) {
            // If the total number of elements is even
            if ((n1 + n2) % 2 == 0) {
                return ((double)(max(l1, l2) + min(r1, r2)) / 2);
            } else {
                return (double)max(l1, l2); // If odd, return the largest element in the left half
            }
        } else if (l1 > r2) {
            // If l1 is too large, we need to move left in nums1
            end = i1 - 1;
        } else {
            // If l2 is too large, we need to move right in nums1
            begin = i1 + 1;
        }
    }

    return 0.0; // This should never be reached if the inputs are valid
}

int main() {
    // Example inputs
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    // Call the function and print the result
    double median = findMedianSortedArrays(nums1, nums2);
    cout << "The median is: " << median << endl;

    return 0;
}
