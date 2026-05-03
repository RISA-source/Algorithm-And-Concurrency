// Reproduce number 2 but instead, print all the numbers to a new text file.

#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp1, *fp2;
	int num, count = 0;
	
	fp1 = fopen("numbers.txt","r");
	fp2 = fopen("even.txt","w");
	
	if(fp1 == NULL){
		printf("FILE NOT FOUND!\n");
		return 1;
	}
	
	while (fscanf(fp1, "%d", &num) == 1){
		if(num % 2 == 0){
			fprintf(fp2,"%d\t", num);
			count++;
		}
	}
	
	printf("\nTotal Even Numbers: %d\n",count);
	printf("\n Saved to file successfully!\n");
	fclose(fp1);
	fclose(fp2);
	return 0;
}
