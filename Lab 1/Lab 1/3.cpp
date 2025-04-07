#include <cstdio>

int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int compareWords(const char* a, const char* b) {
    int lenA = stringLength(a);
    int lenB = stringLength(b);

    if (lenA != lenB) {
        return lenB - lenA;
    }

    for (int i = 0; i < lenA; i++) {
        if (a[i] != b[i]) {
            return a[i] - b[i];
        }
    }
    return 0;
}

void sortWords(char* words[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (compareWords(words[i], words[j]) > 0) {
                char* temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void extractWord(char* source, char* word, int& index) {
    int i = 0;
    while (source[index] == ' ' || source[index] == '\t') {
        index++;
    }

    while (source[index] != '\0' && source[index] != ' ' && source[index] != '\t') {
        word[i++] = source[index++];
    }
    word[i] = '\0';
}

int main() {
    char input[1000];
    char* words[100];
    int wordCount = 0;

    unsigned int size = sizeof(input);
    scanf_s("%[^\n]", input, size);

    int index = 0;
    char word[100];
    while (input[index] != '\0') {
        extractWord(input, word, index);
        if (word[0] != '\0') {
            words[wordCount++] = word;
        }
    }

    sortWords(words, wordCount);

    for (int i = 0; i < wordCount; ++i) {
        printf("%s ", words[i]);
    }
    printf("\n");

    return 0;
}
