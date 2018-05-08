#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "math.h"
#define pi 3.1415926

void GetTheBiggerOneFrom2Ints(){
	int a, b;
	printf("请输入a:");
	scanf("%d", &a);
	printf("请输入b:");
	scanf("%d", &b);
	if(a > b){
		printf("a比较大，数值为%d", a);
	}
	else if(a < b){
		printf("b比较大，数值为%d", b);
	}
	else{
		printf("a和b同样大，数值为%d", a);
	}
}

void GetTheBiggestOneFrom3Ints(){
	int a, b, c;
	printf("请输入a");
	scanf("%d", &a);
	printf("请输入b");
	scanf("%d", &b);
	printf("请输入c");
	scanf("%d", &c);
	if(a > b && a > c){
		printf("a比较大，数值为%d\n", a);	
	}
	else if(b > a && b > c){
		printf("b比较大，数值为%d\n", b);	
	}
	else if(c > a && c > b){
		printf("c比较大，数值为%d\n", c);	
	}
	else if(b = a && b > c){
		printf("b和a比较大，数值为%d\n", b);	
	}
	else if(b = c && b > a){
		printf("b和c比较大，数值为%d\n", b);	
	}
	else if(a = c && a > b){
		printf("a和c比较大，数值为%d\n", a);	
	}
	else{
		printf("三个数一样大，数值为%d\n", a);		
	}
}

void AddTo100(){
	int i = 0, j = 1;
	do{
		i+=j;
		j++;
	}while(j<=100);
	printf("do-while循环下结果为%d\n", i);
	i = 0;
	j = 1;
	while(j<=100){
		i+=j;
		j++;
	}
	printf("while循环下结果为%d\n", i);
}

void InitDoubleListA(){
	double a[10];
	int i;
	a[0] = 10;
	a[2] = -3;
	a[1] = (a[2] - a[0])/3;
	for(i = 3; i < 10; i++){
		a[i] = 3*a[i-1] + a[i-2];
	}
	for (i = 0; i < 10; i++){
		printf("a(%d)的值为%d\n", (i+1), a[i]);
	}
}

void JudgeOddNumOrEvenNum(){
	int a;
	printf("请输入一个需要判断的数字：\n");
	scanf("%d", a);
	if(a%2 == 1){
		printf("您输入的数字是一个奇数\n");
	}
	else{
		printf("您输入的数字是一个偶数\n");
	}
}

void GetSumOfArrayListA(){
	int a[10], b[10];
	int i, sum = 0;
	b[0] = 1;
	for (i = 1; i < 10; i++){
		b[i] = b[i-1] + 3;
	}
	for(i = 1; i < 10; i++){
		a[i] = a[i-1] + b[i];
	}
	for(i = 0; i < 10; i++){
		sum+=a[i];
	}
	printf("%d\n", sum);
}

void Function(){
	double x, Y;
	scanf("%d", &x);
	if(x<1){
		Y = x;
	}
	else if(x >= 1 || x < 10){
		Y = 2 * x -1;
	}
	else{
		Y = 3 * x -11;
	}
	printf("Y的值为%d\n", Y);
}
/*
void GuessInt(){
	int flag = 0, token;
	unsigned int answer;
	srand((unsigned int)time(NULL));
	answer = rand()%5;
	//randomize();1

	//answer = random(5);
	while(1){
		printf("请输入您猜测的值:\n");
		scanf("%d", &token);
		if(token > answer){
			printf("The int you guess is too big!%d\n", answer);
		}
		else if( token < answer){
			printf("The int you guess is too small!\n");
		}
		else{
			printf("Bingo!\n");
		}
		flag++;
		if(flag == 20){
			printf("You could not do it any more!\n");
			break;
		}
	}
}*/

void Test11(){
	int m, n, a, b, t, c;  
   printf("Input two integer numbers:\n");  
   scanf("%d%d", &a, &b);  
   m=a;   n=b;  
   while(b!=0)  /* 余数不为0，继续相除，直到余数为0 */   
   { c=a%b; a=b;  b=c;}  
   printf("The largest common divisor:%d\n", a);  
   printf("The least common multiple:%d\n", m*n/a);  
}

void ContainHowMany2(){
	int a, flag = 0;
	scanf("%d", &a);
	while(a%2 == 0){
		flag++;
		a/=2;
	}
	printf("%d", flag);
}

void Test13(){
	int i,j;
	int k=1;
	for(i = 1; i <= 10; i++){
		for(j=i; j>0; j--){
			k*=j;
		}
		printf("%d\n", k);
		k = 1;
	}
}

int AddPeach(int a){
	return (a+1)*2; 
}

void AllPeach(){
	int a = AddPeach(AddPeach(AddPeach(AddPeach(AddPeach(AddPeach(AddPeach(AddPeach(AddPeach(1)))))))));
	printf("%d", a);
}

void CalculateV(){
	int r, h;
	double v;
	scanf("%d", &r);
	printf("%d", r);
	scanf("%d", &h);
	printf("%d", h);
	v = (1/3)*pi*r*r*h;
	printf("%f", v);

}
void Test8(){
	int a, token, flag = 0;
	printf("Please input an Integer smaller than 100 000:\n");
	scanf("%d", &a);
	do{
		token = a % 10;
		a /= 10;
		flag++;
		printf("%d", token);	
	}while(a != 0);
	printf("总共有%d位\n", flag);
}

void Test10(){
	int i, flag = 0, token, a;
	for(i = 1; i <= 999; i++){
		a = i;
		if(a % 3 == 0){			
			do{
				token = a % 10;
				a /= 10;
				if(token == 5){
					flag = 1;
				}
			}while(a != 0);	
		}
		if(flag){
			printf("%d\n", i);
			flag = 0;
		}
	}
}

void LoginToCheckGrades(){
	int a, flag = 0, truePassword = 7861, thePassword, grade;
	for(a = 3; a>0; a--){
		printf("Please enter your password:\n");
		scanf("%d", &thePassword);
		if(thePassword == truePassword){
			flag = 1;
			break;
		}
		if(a != 1){
			printf("Input error,please retry!\n\n");
		}
		else{
			printf("The system will be closed!\n\n");
		}
	}
	if(flag){
		printf("Please enter the grade you wanna check:\n");
		scanf("%d", &grade);
		if(grade > 100 || grade < 0){
			printf("The grade you have input is illegal!\n");
		}
		else{
			switch(grade){
				case 10: 
					printf("Excellent!");
					break;
				case 9: 
					printf("Great!");
					break;
				case 8:
					printf("Good!");
					break;
				case 7:
					printf("Well!");
					break;
				case 6:
					printf("Just so so!");
					break;
				default:
					printf("Low!");
					break;			
			}
		}
	}
}

void Blank2(){
	int i, j, p, s;
	s = 0;
	for(i=1; i<=4; i++){
		p=1;
		for(j=1;j<=4;j++)
			p=p*j;
		s=s+p;
	}
	printf("s=%d\n", s);
}

void Blank3(){
	char c;
	do{
		printf("enter:");
		scanf("%c", &c);
		if('a'<=c&&c<='z'){
			printf("%c\n", c-32);
//			printf("%c\n", 'c-32');这样会输出2
		}
	}while(c!='$');
}

void main(){
//	AddTo100();
	Test8();
//	Test10();
//  LoginToCheckGrades();
//	Blank2();
//	Blank3();
//	GetSumOfArrayListA();
//	GuessInt();
//	Test11();
//	ContainHowMany2();
//	Test13();
//	AllPeach();
//	CalculateV();
}
