// Using the command line arguments (argv), copy the contents of one file to another
// file. For example. If you run your program with “./a.out file1.txt file2.txt”, your
// program should transfer the content from file1 to file2


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *src, *dest;
	char ch;
	
	if(argc != 3){
		printf("Usage:./a.out source.txt dest.txt\n");
		return 1;
	}
	
	src = fopen(argv[1], "r");
	dest = fopen(argv[2], "w");
	
	if(src == NULL || dest == NULL){
		printf("File Error\n");
		return 1;
	}
	
	
	while ((ch = fgetc(src)) != EOF){
		fputc(ch, dest);
	}
	
	fclose(src);
	fclose(dest);
	
	printf("\nFile Copied Successfully!\n");
	
	return 0;
}
