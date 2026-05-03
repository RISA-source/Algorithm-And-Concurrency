#include <stdio.h>

int main() {

    int n = 1, triangular;
    while(n <= 50){
    	triangular = (n * (n + 1))/ 2;
    	printf("%d  ",triangular);
    	n++;
    }
    return 0;
}
