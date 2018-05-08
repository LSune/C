#include <stdio.h>
#include <math.h>

double sin(doule x){
  double sum;
  int token = 2;
  while(x > 0.000000001){
	sum += x;
	x = x * (-1) * (x * x) / (token * (token + 1));
	token += 2;
  }
  return sum;
}
void main(){
  double x, y;
  printf("Please input a & b:\n");
  scanf("%lf%lf", &x, &y);
  y = //confusing= =
}