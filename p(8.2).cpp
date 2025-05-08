
#include <iostream>
#include <map>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

string normalizeWord(const string& word) {
    string result;
    for (char ch : word) {
        if (isalnum(ch))
            result += tolower(ch);
    }
    return result;
}

void analyzeWordFrequency(const string& text) {
    map<string, int> wordFrequency;
    stringstream ss(text);
    string word;

    while (ss >> word) {
        string cleanWord = normalizeWord(word);
        if (!cleanWord.empty())
            ++wordFrequency[cleanWord];
    }

    cout << "\n--- Word Frequency Analysis ---\n";
    for (auto it = wordFrequency.begin(); it != wordFrequency.end(); ++it) {
        cout << it->first << " : " << it->second << '\n';
    }
}

int main() {
    string inputLine;

    cout << "Enter a sentence or paragraph:\n";
    getline(cin, inputLine);

    if (inputLine.empty()) {
        cerr << "No input provided. Exiting.\n";
        return 1;
    }

    analyzeWordFrequency(inputLine);
    return 0;
}
