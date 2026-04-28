// Read in the text file called numbers1.txt and detect all even numbers.

#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	int num, count = 0, even = 0;
	
	fp = fopen("numbers.txt","r");
	
	if(fp == NULL){
		printf("FILE NOT FOUND!\n");
		return 1;
	}
	
	while (fscanf(fp, "%d", &num) == 1){
		if (num % 2 == 0){
			printf("%d\t",num);
			even++;
		}
		count++;
	}
	
	printf("\nTotal Numbers: %d\n",count);
	printf("\nTotal Even Numbers: %d\n",even);
	fclose(fp);
	return 0;
}
