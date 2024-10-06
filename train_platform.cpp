#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPlatforms(vector<int>& arrival, vector<int>& departure, int n) {
    // Sort the arrival and departure times
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int platform = 1;  // We need at least 1 platform initially
    int result = 1;    // Result to store the maximum platforms needed
    int i = 1, j = 0;  // i for arrival, j for departure

    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            platform++;  // A new train arrives, increase platforms
            i++;  // Move to the next arrival
        } else {
            platform--;  // A train departs, decrease platforms
            j++;  // Move to the next departure
        }

        // Update the result if we need more platforms
        if (platform > result) {
            result = platform;
        }
    }

    return result;
}

int main() {
    int n;

    // Input number of trains
    cout << "Enter the number of trains: ";
    cin >> n;

    vector<int> arrival(n), departure(n);

    // Input arrival times
    cout << "Enter the arrival times: ";
    for (int i = 0; i < n; i++) {
        cin >> arrival[i];
    }

    // Input departure times
    cout << "Enter the departure times: ";
    for (int i = 0; i < n; i++) {
        cin >> departure[i];
    }

    // Call the function to find the minimum number of platforms
    int result = minPlatforms(arrival, departure, n);

    // Output the result
    cout << "Minimum number of platforms required: " << result << endl;

    return 0;
}
