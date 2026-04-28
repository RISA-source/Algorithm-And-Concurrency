// Read in Words.txt and encrypt all the characters by adding 3 to the ascii value. For
// example, the letter a will translate to d. The letter h will translate to k. You should
// then print this value to a text file.


#include <stdio.h>

int main() {
    FILE *inFile, *outFile;
    int ch;

    inFile = fopen("Words.txt", "r");
    if (inFile == NULL) {
        printf("Error: Could not open 'Words.txt'\n");
        printf("Make sure the file exists in the same folder.\n");
        return 1;
    }

    outFile = fopen("encrypted.txt", "w");
    if (outFile == NULL) {
        printf("Error: Could not create 'encrypted.txt'\n");
        fclose(inFile);
        return 1;
    }

    while ((ch = fgetc(inFile)) != EOF) {
        fputc(ch + 3, outFile);
    }

    fclose(inFile);
    fclose(outFile);

    printf("Encryption completed successfully!\n");
    printf("Encrypted content has been written to 'encrypted.txt'\n");

    return 0;
}
