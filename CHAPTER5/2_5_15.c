#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define prerand() (srand((int)time(0)))
#define random(x) (rand()%x)
#define m 10
#define n 10
#define N 45
#define stuColumn 5


void InitialMatrix(int a[][n]){
  int i, j;
  prerand();
  for(i=0; i<m; i++){
    for(j=0; j<n; j++){
      a[i][j] = random(998);
    }
  }
}

void InitialGrades(int a[][stuColumn]){
  int i, j;
  prerand();
  for(i=0; i<N; i++){
    a[i][0] = i;
    for(j=1; j<stuColumn-1; j++){
      a[i][j] = 50 + random(51);
    }
    a[i][4] = (a[i][1]+a[i][2]+a[i][3])/3;
  }
}

void ShowMatrix(int a[][n]){
  int i, j;
  for(i=0; i<m; i++){
    for(j=0; j<n; j++){
      printf("%d\t", a[i][j]);
    }
    printf("\n");
  }
}

void ShowGrades(int a[][stuColumn]){
  int i, j;
  for(i=0; i<N; i++){
    for(j=0; j<stuColumn; j++){
      printf("%d\t", a[i][j]);
    }
    printf("\n");
  }
}
int PlusAll(int a[][n]){
  int i, j, sum = 0;
  for(i=0; i<m; i++){
    for(j=0; j<n; j++){
      sum+=a[i][j];
    }
  }
  return sum;
}

void SearchForBiggest(int a[][n]){
  int i, j, max, row, column;
  max = a[0][0];
  row = 0;
  column = 0;
  for(i=0; i<m; i++){
    for(j=0; j<n; j++){
      if(max < a[i][j]){
        row = i;
        column = j;
        max = a[i][j];
      }
      else{
      }
    }
  }
  for (i=0; i<m; i++){
    for (j=0; j<n; j++){
      if (a[i][j] == max){
        /**
        *Because of the row & the column is always be (the true num) - 1
        *So we plus 1 to the row & the column
        */
        printf("The biggest one in the matrix is: %d\nIts row is: row %d\nIts column is: column %d\n", max, row+1, column+1);
      }
    }
  }
}

void QuickSort(int a[][stuColumn], int left, int right){
  int i, j, x, y;
  int token[stuColumn], temp[stuColumn];
  if(left>right){
    return ;
  }
  i = left;
  j = right;
  for(x=0; x<stuColumn; x++){
    token[x] = a[i][x];
  }
  while(i!=j){
    while(j>i && a[j][4]<=token[4]){
      j--;
    }
    while(j>i && a[i][4]>=token[4]){
      i++;
    }
    if(j>i){
      for(x=0; x<stuColumn; x++){
        temp[x] = a[j][x];
        a[j][x] = a[i][x];
      }
      for(x=0; x<stuColumn; x++){
        a[i][x] = temp[x];
      }
    }
  }
  for(x=0; x<stuColumn; x++){
    a[left][x] = a[i][x];
    a[i][x] = token[x];
  }
  QuickSort(a, left, i-1);
  QuickSort(a, i+1, right);
}

int CalculusPrimeSum(int a[][n]){
  int i;
  int _primeSum = 0;
  for(i=0; i<n; i++){
    _primeSum+=a[i][i];
  }
  return _primeSum;
}

void LookForTopOnes(int a[][n], int top[]){
  int i, j, max;
  for(i=0; i<n; i++){
    max = a[i][0];
    for(j=0; j<n; j++){
      if(a[i][j] > max){
        max = a[i][j];
      }
    }
    top[i] = max;
  }
}

void ShowLineMatrix(int a[], int nn){
  int i;
  for(i=0; i<nn; i++){
    printf("%d\t", a[i]);
  }
  printf("\n");
}

void QuickLineSort(int a[], int left, int right){
  int i, j, temp, token;

  if (left>right){
	  return ;
	}
	i = left;
  j = right;
  token = a[i];
  while (i!=j){
    while (j>i && a[j]>=token){
      j--;
    }
    while (j>i && a[i]<=token){
      i++;
    }
    if (j>i){
      temp = a[j];
      a[j] = a[i];
      a[i] = temp;
    }
  }
  a[left] = a[i];
  a[i] = token;
  QuickLineSort(a, left, i-1);
  QuickLineSort(a, i+1, right);

}

void StatisticAllKindsOfInts(int a[], int nn, int* positive, int* negative, int* zero){
  int i;
  for(i=0; i<nn; i++){
    if(a[i] < 0){
      (*negative)++;

    }
    else if(a[i] > 0){
      (*positive)++;
    }
    else{
      (*zero)++;
    }
  }
}

void StatisticSaddlePoint(int a[][n], int b[][n]){
  int i, j, max, min, flag = 0;
  for(i = 0; i < n; i++){
    max = a[i][0];
    for(j = 0; j < n; j++){
      if(a[i][j] > max){
        max = a[i][j];
      }
    }
    for(j = 0; j < n; j++){
      if(a[i][j] == max){
        b[i][j]++;
      }
    }
    min = a[0][j];
    for(j = 0; j < n; j++){
      if(a[j][i] < min){
        min = a[j][i];
      }
    }
    for(j = 0; j < n; j++){
      if(a[j][i] == min){
        b[j][i]++;
      }
    }
  }
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      if(b[i][j] == 2){
        flag = 1;
        printf("Saddle point is %d, in line %d and column %d.\n", a[i][j], i+1, j+1);
      }
    }
  }
  if(!flag){
    printf("There is no saddle point.\n");
  }
}

int main()
{
  int a[m][n], students[N][stuColumn];
  int b[m][n] = {0};
  int top[n];
  int row, column, max;
  int *positive, *negative, *zero;
  positive = (int*)malloc(sizeof(int));
  negative = (int*)malloc(sizeof(int));
  zero = (int*)malloc(sizeof(int));
  * positive = 0;
  * negative = 0;
  * zero = 0;

  InitialMatrix(a);
  ShowMatrix(a);
  printf("The sum of every item in the matrix is %d\n", PlusAll(a));
  printf("The prime sum of this matrix is %d\n", CalculusPrimeSum(a));
  LookForTopOnes(a, top);
  ShowLineMatrix(top, n);
  QuickLineSort(top, 0, n-1);
  ShowLineMatrix(top, n);
  StatisticAllKindsOfInts(top, n, positive, negative, zero);
  printf("There are %d positive Ints, %d negative Ints and %d zeros.\n", *positive, *negative, *zero);
  StatisticSaddlePoint(a, b);
  SearchForBiggest(a);
  //students part:
  InitialGrades(students);
  QuickSort(students, 0, N-1);
  ShowGrades(students);
  getchar();
  free(positive);
  free(negative);
  free(zero);
  return 0;
}
