# include <stdio.h>
# define division 100

double sin(double x){
  double sum = 0;
  int token = 0, temp = x;
  while(token <= division){
	sum += temp;
	token += 2;
	temp = temp * (-1) * (x * x) / (token * (token + 1));
  }
  return sum;
}

double exponential(double x){
  double temp = 1, sum = 0, i = 0;
  while (i < division){
	sum += temp;
	i++;
	temp = temp * x / i;
  }
  return sum;
}

double Function(double x){
  return x * x + sin(x) * exponential(x);
}

double Integrate(int acc, double start, double end){
  int i;
  double sum = 0;
  for(i = 0; i < acc; i++){
	sum += Function(start + i * ((end - start)/acc)) * (end - start) / acc;
  }
  return sum;
}
void main(){
  double ans;
  ans = Integrate(division, 0, 1);
  printf("%lf", ans);
}