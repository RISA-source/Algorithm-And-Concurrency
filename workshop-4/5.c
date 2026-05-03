// Using the command line arguments (argv), merge the contents of two files and print
// them out to another. For example, when you run your program with ./a.out file1.txt
// file2.txt file3.txt, the contents from file1 and file2 will be combined and printed to
// file3. Both files you will need to create yourself, it doesn’t matter what is inside, just
// as long as you’re able to see the merge at the end.


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *f1, *f2, *f3;
	char ch;
	
	if(argc != 4){
		printf("Usage:./a.out source.txt dest.txt\n");
		return 1;
	}
	
	f1 = fopen(argv[1], "r");
	f2 = fopen(argv[2], "r");
	f3 = fopen(argv[3], "w");
	
	if(f1 == NULL || f2 == NULL || f3 == NULL){
		printf("File Error\n");
		return 1;
	}
	
	
	while ((ch = fgetc(f1)) != EOF){
		fputc(ch, f3);
	}
	
	while ((ch = fgetc(f2)) != EOF){
		fputc(ch, f3);
	}
	
	fclose(f1);
	fclose(f2);
	fclose(f3);
	
	printf("\nFile Merged and Saved!\n");
	
	return 0;
}
