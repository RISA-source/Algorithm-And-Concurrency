// Read in Words.txt which contains a single paragraph, perform the following:
//  a. Print out how many times the letter “c” is found in the text file.
//  b. Print out how many words are in the text file.
//  c. Print out how many punctuation symbols are used (, . - / etc)


#include <stdio.h>
#include <ctype.h>   // for tolower()

int main() {
    FILE *fp;
    int ch;
    int count_c = 0;
    int word_count = 0;
    int punct_count = 0;
    int in_word = 0;   // flag to detect word boundaries

    fp = fopen("Words.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open 'Words.txt'\n");
        printf("Make sure the file exists in the same folder as the program.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {

        if (tolower(ch) == 'c') {
            count_c++;
        }

        if (ch == ',' || ch == '.' || ch == '-' || ch == '/' ||
            ch == '!' || ch == '?' || ch == ';' || ch == ':' ||
            ch == '\'' || ch == '"' || ch == '(' || ch == ')' ||
            ch == '[' || ch == ']' || ch == '{' || ch == '}') {
            punct_count++;
        }

        if (isspace(ch)) {
            in_word = 0;
        } else {
            if (in_word == 0) {
                word_count++;
                in_word = 1;
            }
        }
    }
    fclose(fp);

    printf("=== Analysis of Words.txt ===\n");
    printf("Number of letter 'c' (case insensitive): %d\n", count_c);
    printf("Total number of words: %d\n", word_count);
    printf("Total punctuation symbols: %d\n", punct_count);

    return 0;
}
