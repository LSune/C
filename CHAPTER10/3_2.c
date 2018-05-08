#include "stdio.h"
#define LEAPYEAR(x) (((x%400==0)||(x%4==0&&x%100!=0))?1:0)

int main(){
  while(1){
    printf("Please input the year you want to check:\n");
    int x;
    scanf("%d", &x);
    if(LEAPYEAR(x)){
      printf("The year you input is a lunaer year\n");
    }
    else{
      printf("The year you input is not a lunaer year\n");
    }
  }
}
