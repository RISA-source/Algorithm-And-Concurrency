#include <stdio.h>
#include <string.h>

struct Book {
    int accession;
    char author[50];
    char title[100];
    int copies;        // flag: number of copies available (0 = issued/not available)
};
struct Book library[100];
int bookCount = 0;
void displayBook(struct Book b) {
    printf("Accession: %d | Title: %s | Author: %s | Copies: %d\n", 
           b.accession, b.title, b.author, b.copies);
}
int main() {
    int choice;    
    while (1) {
        printf("\n=== Library Menu ===\n");
        printf("1. Add a new book\n");
        printf("2. Display all books\n");
        printf("3. Display books by author\n");
        printf("4. Display count of a particular title\n");
        printf("5. Total books in library\n");
        printf("6. Issue a book (decrease copies)\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);        
        if (choice == 0) break;        
        if (choice == 1) {  // Add book
            printf("Enter accession, title, author, copies: ");
            scanf("%d", &library[bookCount].accession);
            scanf(" %[^\n]", library[bookCount].title);
            scanf(" %[^\n]", library[bookCount].author);
            scanf("%d", &library[bookCount].copies);
            bookCount++;
            printf("Book added!\n");
        }
        else if (choice == 2) {  // Display all
            for (int i = 0; i < bookCount; i++)
                displayBook(library[i]);
        }
        else if (choice == 3) {  // By author
            char auth[50];
            printf("Enter author name: ");
            scanf(" %[^\n]", auth);
            for (int i = 0; i < bookCount; i++) {
                if (strcmp(library[i].author, auth) == 0)
                    displayBook(library[i]);
            }
        }
        else if (choice == 4) {  // Count by title
            char tit[100];
            int cnt = 0;
            printf("Enter title: ");
            scanf(" %[^\n]", tit);
            for (int i = 0; i < bookCount; i++) {
                if (strcmp(library[i].title, tit) == 0)
                    cnt += library[i].copies;
            }
            printf("Total copies of '%s': %d\n", tit, cnt);
        }
        else if (choice == 5) {
            printf("Total books in library: %d\n", bookCount);
        }
        else if (choice == 6) {  // Issue book
            int acc;
            printf("Enter accession number to issue: ");
            scanf("%d", &acc);
            for (int i = 0; i < bookCount; i++) {
                if (library[i].accession == acc && library[i].copies > 0) {
                    library[i].copies--;
                    printf("Book issued successfully!\n");
                    break;
                }
            }
        }
    }
    return 0;
}
