#include <stdio.h>

struct Employee {
    char name[50];
    float salary;
    int hours;
};

int main() {
    struct Employee emp[5];
    
    // Input data for 5 employees
    for (int i = 0; i < 5; i++) {
        printf("Enter name, salary and hours for employee %d: ", i+1);
        scanf("%s %f %d", emp[i].name, &emp[i].salary, &emp[i].hours);
    }
    
    // Increase salary based on hours
    for (int i = 0; i < 5; i++) {
        if (emp[i].hours >= 12)
            emp[i].salary += 150;
        else if (emp[i].hours >= 10)
            emp[i].salary += 100;
        else if (emp[i].hours >= 8)
            emp[i].salary += 50;
    }
    
    // Print final salaries
    printf("\nFinal Salaries:\n");
    for (int i = 0; i < 5; i++) {
        printf("%-15s : $%.2f\n", emp[i].name, emp[i].salary);
    }
    
    return 0;
}
