#include <stdio.h>


int squSum(int x, int y){
  return x*x+y*y;
}

void EuclideanAlgorithm(int * a, int * b, int x, int y){
  int token, flag;
  if(x > y){
	token = x % y;
	flag = 1;
  }
  else{
	token = y % x;
	flag = 0;
  }
  * a = flag ? y : x;
  while(token != 0){
	* b = token;
	token = * a % token;
	* a = * b;
  }
  * b = x / (* a) * y;
}

void JudgePrimeNum(int z){
  int flag = 0, i;
  for(i = 2; i < z; i++){
	if(z % i == 0){
	  flag = 1;
	  break;
	}
  }
  if(flag){
	printf("%d is not a PrimeNum.\n", z);
  }
  else{
	printf("%d is a PrimeNum.\n", z);
  }
}

int PowXwith3(int x){
  return x * x * x;
}

void IfNarcissisticNum(int z){
  int a, b, c;
  if(z>99 && z<1000){
	a = z/100;
	b = z/10 - a * 10;
	c = z - b * 10 - a * 100;
	if(z == PowXwith3(a) + PowXwith3(b) + PowXwith3(c)){
	  printf("%d is a Narcissistic Num.\n", z);
	}
	else{
	  printf("%d is not a Narcissistic Num.\n", z);
	}
  }
  else{
	printf("%d is not a Narcissistic Num.\n", z);
  }
}

void main(){
  int a, b, x, y;
  scanf("%d %d", &x, &y);
  JudgePrimeNum(x);
  JudgePrimeNum(y);
  IfNarcissisticNum(x);
  IfNarcissisticNum(y);
  EuclideanAlgorithm(&a, &b, x, y);
  printf("The squsum is %d,\nand the Greatest Common divisor is %d,\nthe Least Common Multiple is %d. \n",squSum(a,b), a, b);
  getchar();
}


