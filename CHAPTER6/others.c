#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15

enum STATUS {high, nor, low};

struct Node{
  struct Node * next;
  int data;
};

void PreRand(){
  srand((int)time(0));
}

int Random(int x){
  return rand()%x;
}

double OddSum (int n){
  double sum = 0;
  // we may use 0 to judge odd and even condition.
  do{
    sum += (1.0/n);
    n -= 2;
  }while(n != -1);
  return sum;
}

double EvenSum (int n){
  double sum = 0;
  do{
    sum += (1.0/n);
    n -= 2;
  }while(n != 0);
  return sum;
}

double Sum (int n, double (*fun) (int)){
  return fun(n);
}

void PointerBubbleSort(int ** a, int n){
  int i, j;
  int * temp;
  for(i = 0; i < n; i++){
    for(j = 0; j < n - i - 1; j++){
      if(**(a + j) < **(a + j + 1)){
        temp = *(a + j);
        *(a + j) = *(a + j + 1);
        *(a + j + 1) = temp;
      }
    }
  }
}

int ** Initialize(int a[], int * aa[], int ** aaa, int n){
  int i;
  PreRand();
  for(i = 0; i < n; i++){
    a[i] = Random(50);
    aa[i] = &a[i];
  }
  return &aa[0];
}

void PointerPointerShow(int ** aaa, int n){
  int i;
  for(i = 0; i < n; i++){
    printf("%d\t", **(aaa + i));
  }
}

void PrintMax(int a, int b){
  printf("%d", a>b?a:b);
}

void PrintMin(int a, int b){
  printf("%d", a>b?b:a);
}

void RunPointerFun(int a, int b, void (* fun1) (int, int),
                   void (* fun2) (int, int), int flag){
  switch (flag){
    case 1:
      (* fun1) (a, b);
      break;
    case 2:
      (* fun2) (a, b);
      break;
  }
}

void NodeInit(struct Node num[], int n){
  int i;
  for(i = 0; i < n - 1; i++){
    num[i].data = i;
    num[i].next = &num[i + 1];
  }
  num[i].data = i;
  num[i].next = &num[0];
}

void NodeList(struct Node num[], struct Node * head){
  struct Node * pointer = head;
  while(pointer -> next != head){
    printf("%d\t", pointer -> data);
    pointer = pointer -> next;
  }
}

  /**
   *use 2 different ways to achieve fun
   */
void InitStu(int (* stu) [7], enum STATUS * sta){
  int i, j, highToken, lowToken;
  double temp;
  PreRand();
  for(i = 0; i < 4; i++){
    highToken = 0;
    lowToken = 0;
    temp = 0;
    // initialize the Stu Number.
    *(*(stu + i) + 0) = i;
    for(j = 1; j < 6; j++){
      *(*(stu + i) + j) = Random(50) + 50;
      temp += *(*(stu + i) + j);

      // grades statistic
      if(*(*(stu + i) + j) > 85){
        highToken++;
      }
      else if(*(*(stu + i) + j) < 60){
        lowToken++;
      }
      else{

      }

      // update the status of every student
      if(highToken == 5){
        * (sta + i) = high;
      }
      else if(lowToken == 2){
        * (sta + i) = low;
      }
      else{

      }
    }
    //update the average grade
    stu[i][6] = (temp / 5);
    if(stu[i][6] > 90){
      * (sta + i) = high;
    }
    else{

    }
  }
}

void FirstAvg(int stu[][7], int n){
  int i, sum = 0;
  for(i = 0; i < n; i++){
    sum += stu [i][1];
  }
  printf("The 1st class avg is %.2f\n", (sum / 1.0) / (n * 1.0));
}

// error when use ［int * stu,］
void SelectStu(enum STATUS * sta, int stu[][7], int n){
  int i = 0, j;
  for(i = 0; i < n; i++){
    if(*(sta + i) == low){
      printf("The student %d got the low grades,\ngrades are %d, %d, %d, %d, %d,\navg is %d.\n",
           stu[i][0], stu[i][1], stu[i][2], stu[i][3], stu[i][4], stu[i][5], stu[i][6]);
    }
    else if(*(sta + i) == high){
      printf("The student %d got the high grades,\ngrades are %d, %d, %d, %d, %d,\navg is %d.\n",
           stu[i][0], stu[i][1], stu[i][2], stu[i][3], stu[i][4], stu[i][5], stu[i][6]);
    }
  }
}

int main()
{
  double sum;
  int n, var_1, var_2, flag, m;
  int a[25];
  int * aa[25];
  int ** aaa;
  struct Node num[N];
  struct Node * head = &num[0];
  int stu[4][7];
  enum STATUS sta[4] = {nor, nor, nor, nor};

  /**
   *Test 3_2
   */
  NodeInit(num, N);
  NodeList(num, head);
  printf("\nPlease input the Key n:\n");
  scanf("%d", &m);
  head = &num[N - m];
  NodeList(num, head) ;

  /**
   *Test 3_5
   */
  scanf("%d", &n);
  if (n%2 == 0){
    sum = Sum(n, EvenSum);
  }
  else{
    sum = Sum(n, OddSum);
  }
  printf("%f\n", sum);

  /**
   *Test 3_6
   *meet an error when this part is in front of
   *the part above it
   */
  aaa = Initialize(a, aa, aaa, 25);
  PointerPointerShow(aaa, 25);
  printf("\n");
  PointerBubbleSort(aaa, 25);
  PointerPointerShow(aaa, 25);
  printf("\n");

  /**
   *Test 3_7
   */
  printf("Please input 2 int:\n");
  scanf("%d %d", &var_1, &var_2);
  printf("Input 1 to get the bigger one, 2 to get the smaller one\n");
  scanf("%d", &flag);
  RunPointerFun(var_1, var_2, PrintMax, PrintMin, flag);

  /**
   *Test 3_8
   */
  InitStu(stu, sta);
  FirstAvg(stu, 4);
  SelectStu(sta, stu, 4);

  return 0;
}
