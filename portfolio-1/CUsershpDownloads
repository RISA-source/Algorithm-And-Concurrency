/* 
 * Module: 5CS046 - Algorithms and Concurrency
 * Assessment: Portfolio Task 1 - Linear Regression
 * Name: Rishi Saraff
 * Student ID: 2501941
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile(const char *filename, double **xArr, double **yArr, int *n);
void calculateSums(double *xArr, double *yArr, int n, double *sumX, double *sumY, double *sumXY, double *sumX2);
void computeAB(double sumX, double sumY, double sumXY, double sumX2, int n, double *a, double *b);
void printEquation(double a, double b);
double predictY(double a, double b);
void freeMemory(double *xArr, double *yArr);

void readFile(const char *filename, double **xArr, double **yArr, int *n){
	FILE *file = fopen(filename, "r");
	if (file == NULL){
		printf("Error: Could not open file '%s'\n", filename);
		exit(1);
	}
	int capacity = 10;
	*n = 0;
	*xArr = (double *)malloc(capacity * sizeof(double));
	*yArr = (double *)malloc(capacity * sizeof(double));
	if(*xArr == NULL || *yArr == NULL){
		printf("Error: Memory Allocation Failed\n");
		exit(1);
	}
	double x, y;
	while (fscanf(file, "%lf,%lf", &x, &y) == 2) {
        	if (*n == capacity) {
			capacity *= 2;
            		double *tempX = (double *)realloc(*xArr, capacity * sizeof(double));
            		double *tempY = (double *)realloc(*yArr, capacity * sizeof(double));
            		if (tempX == NULL || tempY == NULL) {
                		printf("Error: Memory reallocation failed\n");
                		fclose(file);
                		free(*xArr);
                		free(*yArr);
                		exit(1);
            		}
            		*xArr = tempX;
            		*yArr = tempY;
        	}

	        (*xArr)[*n] = x;
        	(*yArr)[*n] = y;
	        (*n)++;
    	}
	fclose(file);
}

void calculateSums(double *xArr, double *yArr, int n, double *sumX, double *sumY, double *sumXY, double *sumX2){
	*sumX  = 0.0;
	*sumY  = 0.0;
	*sumXY = 0.0;
	*sumX2 = 0.0;

	for (int i = 0; i < n; i++) {
	        *sumX  += xArr[i];
        	*sumY  += yArr[i];
	        *sumXY += xArr[i] * yArr[i];
        	*sumX2 += xArr[i] * xArr[i];
    	}
}

void computeAB(double sumX, double sumY, double sumXY, double sumX2, int n, double *a, double *b){
	*b = ((double)n * sumXY - sumX * sumY) / ((double)n * sumX2 - sumX * sumX);
	*a = (sumY - (*b) * sumX) / (double)n;
}

void printEquation(double a, double b){
	printf("\nEquation of best fit line:\n");

	if (a >= 0) {
        	printf("y = %.4lfx + %.4lf\n", b, a);
	} else {
        	printf("y = %.4lfx - %.4lf\n", b, -a);
	}
}

double predictY(double a, double b){
	double x, y;
	printf("\nEnter a value of x to predict y: ");
	scanf("%lf", &x);
	y = b * x + a;
	printf("For x = %.4lf, predicted y = %.4lf\n", x, y);
	return y;
}

void freeMemory(double *xArr, double *yArr){
	free(xArr);
	free(yArr);
}

int main(){
	char filename[100];
	double *xArr = NULL;
	double *yArr = NULL;
	int n = 0;
	double a, b;
	double sumX, sumY, sumXY, sumX2;
	char ui[10];

	do{
		printf("\n\n");
		printf("Enter filename: ");
		scanf("%s",filename);

		readFile(filename, &xArr, &yArr, &n);
		printf("Read %d data points from file.\n", n);
		calculateSums(xArr, yArr, n, &sumX, &sumY, &sumXY, &sumX2);
		computeAB(sumX, sumY, sumXY, sumX2, n, &a, &b);
		printEquation(a, b);
		predictY(a, b);
		freeMemory(xArr, yArr);

		printf("\nDo you want to continue? (Y/N): \n");
		scanf("%s", ui);
	}while(strcmp(ui, "Y") == 0 || strcmp(ui, "y") == 0);

	return 0;
}
