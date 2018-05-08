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
  int i, j, sum;
  for(i=0; i<m; i++){
    for(j=0; j<n; j++){
      sum+=a[i][j];
    }
  }
  return sum;
}

void SearchForBiggest(int a[][n]){
  int i, j, max, row, cloumn;
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
      else if{
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
int main()
{
  int a[m][n];
  int students[N][stuColumn];
  int row, column, max;
  InitialMatrix(a);
  ShowMatrix(a);
  printf("The sum of every item in the matrix is %d\n", PlusAll(a));
  SearchForBiggest(a);
  //students part:
  InitialGrades(students);
  QuickSort(students, 0, N-1);
  ShowGrades(students);
  getchar();
  return 0;
}
