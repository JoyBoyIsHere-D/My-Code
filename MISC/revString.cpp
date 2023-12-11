#include <iostream>
#include <string>
using namespace std;

string reverse(string s) {
    if (s.length() == 0) {
        return "";  // Return an empty string for the base case
    }

    string rev = reverse(s.substr(1));  // Reverse the rest of the string
    cout << s[0];  // Print the first character
    return rev + s[0];  // Return the reversed string
}

int main() {
    cout << "Enter a string: ";
    string str;
    cin >> str;

    cout << "Reversed string: " << reverse(str) << endl;
    return 0;
}
