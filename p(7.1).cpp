#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const int MAX_WORDS = 100;
const int MAX_LEN = 1000;

struct WordEntry {
    char word[30];
    int count;
};


void toLower(char* str) {
    for (int i = 0; str[i]; ++i)
        str[i] = tolower(str[i]);
}


void cleanWord(char* word) {
    int i = 0, j = 0;
    while (word[i]) {
        if (isalnum(word[i]))
            word[j++] = tolower(word[i]);
        i++;
    }
    word[j] = '\0';
}


int findWord(WordEntry entries[], int size, const char* word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(entries[i].word, word) == 0)
            return i;
    }
    return -1;
}

int main() {
    char paragraph[MAX_LEN];
    WordEntry entries[MAX_WORDS];
    int wordCount = 0;

    cout << "Enter a paragraph:\n";
    cin.getline(paragraph, MAX_LEN);

    char* token = strtok(paragraph, " ");
    while (token != nullptr) {
        cleanWord(token);
        if (strlen(token) == 0) {
            token = strtok(nullptr, " ");
            continue;
        }

        int index = findWord(entries, wordCount, token);
        if (index != -1) {
            entries[index].count++;
        } else if (wordCount < MAX_WORDS) {
            strcpy(entries[wordCount].word, token);
            entries[wordCount].count = 1;
            wordCount++;
        }

        token = strtok(nullptr, " ");
    }

    cout << "\nWord Frequencies:\n";
    for (int i = 0; i < wordCount; i++) {
        cout << entries[i].word << ": " << entries[i].count << endl;
    }

    return 0;
}
