#include <stdio.h>

struct Employee {
    char name[50];
    float salary;
    int hours;
};

// Function that modifies salary using pointer
void increaseSalary(struct Employee *e) {
    if (e->hours >= 12)
        e->salary += 150;
    else if (e->hours >= 10)
        e->salary += 100;
    else if (e->hours >= 8)
        e->salary += 50;
}

int main() {
    struct Employee emp[5];
    
    for (int i = 0; i < 5; i++) {
        printf("Enter name, salary and hours for employee %d: ", i+1);
        scanf("%s %f %d", emp[i].name, &emp[i].salary, &emp[i].hours);
        
        increaseSalary(&emp[i]);   // Pass address
    }
    
    printf("\nFinal Salaries:\n");
    for (int i = 0; i < 5; i++) {
        printf("%-15s : $%.2f\n", emp[i].name, emp[i].salary);
    }
    
    return 0;
}
