// Using scanf, ask the user to type in their name and age, print this data to a text file.
// You should aim to only use one scanf command as you can store memory to an
// integer variable and char array using %s and %d.


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	char name[50];
	int age;
	
	FILE *fp = fopen("user.txt", "w");
	
	if(fp == NULL){
		printf("File Error\n");
		return 1;
	}
	
	printf("Enter Name and Age\n");
	scanf("%s %d", name, &age);
	
	fprintf(fp, "Name: %s\nAge:%d\n",name, age);
	
	fclose(fp);
	
	printf("\nFile Created Successfully!\n");
	
	return 0;
}
