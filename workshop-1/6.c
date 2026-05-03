#include <stdio.h>

int main(){
	int n;
	int a=0,b=1,c; 
	
	printf("Enter a number: \n");
	scanf("%d",&n);
	
	while(n > 0){
		c=a+b;
		printf("%d\n",c);
		a=b;
		b=c;
		n--;
	}
	return 0;
}
