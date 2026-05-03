#include <stdio.h>
#include <string.h>

int main() {
    char word[100];
    char *ptr, *rev;

    printf("Enter a word: ");
    scanf("%s", word);

    printf("You entered: %s\n", word);

    // Check palindrome using pointers
    ptr = word;
    rev = word + strlen(word) - 1;

    int isPal = 1;
    while (rev >= ptr) {
        if (*ptr != *rev) {
            isPal = 0;
            break;
        }
        ptr++;
        rev--;
    }

    if (isPal)
        printf("%s is a PALINDROME\n", word);
    else
        printf("%s is NOT a palindrome\n", word);

    return 0;
}
