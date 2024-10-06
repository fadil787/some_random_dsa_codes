#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the minimum number of platforms required
int findPlatform(vector<int>& arr, vector<int>& dep, int n) {
    int plat_needed = 1;  // Initially, we need 1 platform for the first train
    int res = 1;  // Result stores the maximum platforms needed at any time

    // Loop through the trains to calculate platform requirements
    for (int i = 0; i < n; i++) {
        plat_needed = 1;  // Reset platform count for each train

        // Compare with every other train to find overlaps
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (arr[i] >= arr[j] && dep[j] >= arr[i]) {
                    plat_needed++;  // If trains overlap, increase platform count
                }
            }
        }

        // Update the result with the maximum platforms required at any time
        res = max(res, plat_needed);
    }

    return res;  // Return the maximum platforms required
}

int main() {
    // Example input: arrival and departure times of trains
    int n;  // Number of trains

    cout << "Enter the number of trains: ";
    cin >> n;

    vector<int> arrival(n), departure(n);

    cout << "Enter the arrival times: ";
    for (int i = 0; i < n; i++) {
        cin >> arrival[i];
    }

    cout << "Enter the departure times: ";
    for (int i = 0; i < n; i++) {
        cin >> departure[i];
    }

    // Call the function to find the minimum number of platforms required
    int result = findPlatform(arrival, departure, n);

    // Output the result
    cout << "Minimum number of platforms required: " << result << endl;

    return 0;
}
