#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> arr;  // To hold the input elements
    int element, r;

    // Input: the value of r (multiplier)
    cout << "Enter the value of r: ";
    cin >> r;

    cout << "Enter elements (enter -1 to stop): " << endl;

    // Read input until the user enters -1
    while (true) {
        cin >> element;
        if (element == -1) {
            break;  // Exit the loop when the user enters -1
        }
        arr.push_back(element);  // Store the valid element in the array
    }

    // Create a map to count the frequency of each element
    unordered_map<int, int> freq_map;

    // Calculate frequency of each element
    for (int el : arr) {
        freq_map[el]++;
    }

    // Sum of unique elements
    int unique_sum = 0;
    for (auto &pair : freq_map) {
        unique_sum += pair.first;  // Sum of all unique elements
    }

    // Total sum of elements in the array
    int array_sum = 0;
    for (int el : arr) {
        array_sum += el;
    }

    // The special number
    int special_number = r * unique_sum - array_sum;

    // Output the result
    cout << "The special number that occurs " << r-1 << " times is: " << special_number << endl;

    return 0;
}
