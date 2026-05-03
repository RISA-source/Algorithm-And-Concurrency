#include <stdio.h>
#include <math.h>

// Structure to store roots
struct Roots {
    float r1, r2;
};

// Function to calculate roots
struct Roots calculateRoots(int a, int b, int c) {
    struct Roots r;
    float d = (b * b) - ((4*a)*c);

    if (d >= 0) {
        r.r1 = (-b + sqrt(d)) / (2*a);
        r.r2 = (-b - sqrt(d)) / (2*a);
    } else {
        r.r1 = r.r2 = 0; // imaginary roots (ignored)
    }

    return r;
}

int main() {
    int a, b, c;
    struct Roots res;

    printf("Enter a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);

    res = calculateRoots(a, b, c);

    printf("Roots: %.2f %.2f\n", res.r1, res.r2);

    return 0;
}
