// Read in the text file called numbers1.txt and print out all the data to the terminal. 
// You should also print out how many numbers are within the file.

#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	int num, count = 0;
	
	fp = fopen("numbers.txt","r");
	
	if(fp == NULL){
		printf("FILE NOT FOUND!\n");
		return 1;
	}
	
	while (fscanf(fp, "%d", &num) == 1){
		printf("%d\t", num);
		count++;
	}
	
	printf("\nTotal Numbers: %d\n",count);
	fclose(fp);
	return 0;
}
