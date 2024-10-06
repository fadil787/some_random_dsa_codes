#include <iostream>
#include <string>
using namespace std;

// Function to rearrange the string based on the second example pattern
string rearrangeString(const string& input, int n) {
    int len = input.size();
    string result = "";  // Result string to store the rearranged characters

    // Traverse the string column by column starting from index 0 to n-1
    for (int i = 0; i < n; ++i) {
        // For each starting index i, pick every nth character
        for (int j = i; j < len; j += n) {
            result.push_back(input[j]);  // Append each nth character starting from i
        }
    }

    return result;
}

int main() {
    string input;
    int n;

    // Input
    cout << "Enter the input string: ";
    getline(cin, input);
    cout << "Enter the integer n: ";
    cin >> n;

    // Perform the transformation
    string output = rearrangeString(input, n);

    // Output the result
    cout << "Transformed String: " << output << endl;

    return 0;
}
