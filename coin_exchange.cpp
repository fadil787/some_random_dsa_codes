#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end());  // Sort coins in ascending order
    int i = coins.size() - 1;          // Pointer to start from largest coin
    vector<int> vec;                   // To store the coins used

    if (amount == 0) return 0;         // If the amount is zero, no coins are needed
    
    // Greedy approach to start with the largest coin and try to use it
    while (amount != 0 && i >= 0) {
        if (amount < coins[i]) {
            i--;  // Move to the next smaller denomination
        } else {
            vec.push_back(coins[i]);  // Use the current coin
            amount -= coins[i];       // Reduce the amount
        }
    }

    // If amount is zero, return the number of coins used, else return -1
    return (amount == 0) ? vec.size() : -1;
}

int main() {
    int n, amount;
    
    // Input the number of coins and the coins themselves
    cout << "Enter the number of coins: ";
    cin >> n;
    vector<int> coins(n);
    
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    // Input the amount for which we need to make change
    cout << "Enter the amount: ";
    cin >> amount;
    
    // Call the coinChange function and print the result
    int result = coinChange(coins, amount);
    
    if (result == -1) {
        cout << "It is not possible to make the amount with the given coins." << endl;
    } else {
        cout << "The minimum number of coins needed: " << result << endl;
    }
    
    return 0;
}
