#include <stdio.h>
#include <math.h>

void Get2DiffAns(double a, double b, double delta){
  printf("The one answer is %lf\n, the other answer is %lf\n", (-b+sqrt(delta))/(2*a), (-b-sqrt(delta))/(2*a)	);
}

void Get2SameAns(double a, double b){
  printf("The only one answer is %lf\n", (-b/(2*a)));
}

void Get2ImaginaryAns(double a, double b, double delta){
  printf("The one imaginary answer is %lf+%lfi,\nthe other imaginary answer is %lf-%lfi\n", -b/(2*a), sqrt(-delta)/(2*a), -b/(2*a), sqrt(-delta)/(2*a));
}

void main(){
  double a, b, c, delta;
  printf("eg:aX^2+bX+c=0,please enter the a, b, c in trun.\n");
  scanf("%lf%lf%lf", &a, &b, &c);
  delta = b * b - 4 * a * c;
  if(delta > 0){
	Get2DiffAns(a, b, delta);
  }
  else if(delta == 0){
	Get2SameAns(a, b);
  }
  else{
	Get2ImaginaryAns(a, b, delta);
  }
  getchar();
  getchar();
}