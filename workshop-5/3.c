#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double* quadraticRootsPtr(int a, int b, int c) {
    double* roots = (double*)malloc(2 * sizeof(double));
    if (roots == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    double discriminant = b * b - 4.0 * a * c;
    
    if (discriminant < 0) {
        printf("Roots are complex\n");
        roots[0] = roots[1] = NAN;
    }
    else {
        roots[0] = (-b + sqrt(discriminant)) / (2.0 * a);
        roots[1] = (-b - sqrt(discriminant)) / (2.0 * a);
    }
    return roots;
}

int main() {
    int a, b, c;
    printf("Enter coefficients a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);
    
    double* roots = quadraticRootsPtr(a, b, c);
    
    if (roots != NULL) {
        if (!isnan(roots[0])) {
            printf("Root 1 = %.4f\n", roots[0]);
            printf("Root 2 = %.4f\n", roots[1]);
        }
        free(roots);        // Important!
    }
    
    return 0;
}
