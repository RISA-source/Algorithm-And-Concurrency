#include <stdio.h>

struct Circle{
	double area;
	double perimeter;
};

struct Circle getCircleInfo(double radius){
	struct Circle c;
	double const pi = 3.14159;
	
	c.area = pi * radius * radius;
	c.perimeter = 2 * pi * radius;
	
	return c;
}

int main(){
	double r;
	printf("Enter radius of circle: \n");
	scanf("%1lf",&r);
	
	struct Circle result = getCircleInfo(r);
	printf("Area      = %.4f\n",result.area);
	printf("Perimeter = %.4f\n",result.perimeter);
	
	return 0;	
}
