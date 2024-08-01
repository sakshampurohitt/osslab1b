#include <iostream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

// Function to convert a string to lowercase
string toLower(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Function to clean a word by removing punctuation
string cleanWord(const string& word) {
    string cleaned;
    for (char c : word) {
        if (isalnum(c)) { // Check if the character is alphanumeric
            cleaned += c;
        }
    }
    return cleaned;
}

int main() {
    // Read the paragraph from user
    cout << "Enter a paragraph: ";
    string input;
    getline(cin, input);

    // Convert paragraph to stringstream for easy word extraction
    stringstream ss(input);
    unordered_map<string, int> wordCount;
    string word;

    // Process each word in the paragraph
    while (ss >> word) {
        word = toLower(word); // Convert to lowercase
        word = cleanWord(word); // Remove punctuation
        if (!word.empty()) {
            wordCount[word]++;
        }
    }

    // Output the word frequencies
    cout << "Word frequencies:" << endl;
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
