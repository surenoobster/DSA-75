#include <iostream>
#include <string>

using namespace std;

int main() {
    string x;
    cin >> x;  // Input the number as a string

    int n = x.size();
    
    // Process each digit
    for (int i = 0; i < n; i++) {
        int digit = x[i] - '0';        // Convert the current character to an integer
        int inverted_digit = 9 - digit; // Compute the inverted digit

        // Ensure the first digit doesn't become zero
        if (i == 0 && digit == 9) {
            continue;  // Do not invert leading 9 to avoid leading zero
        }

        // Replace the digit with its inverted value if it's smaller
        if (inverted_digit < digit) {
            x[i] = inverted_digit + '0';  // Convert back to character
        }
    }

    // Output the minimized number
    cout << x << endl;

    return 0;
}

