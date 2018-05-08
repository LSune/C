# include <stdio.h>

void BubbleSort(int a[], int n){
  int i, j, temp;
  for (i=0; i<n-1; i++){
    for (j=i; j<n-1; j++){
      if (a[j]>a[j+1]){
      temp = a[j+1];
      a[j+1] = a[j];
      a[j] = temp;
      }
      else{
      }
    }
  }
}

void SelectSort(int a[], int n){
  int i, j, temp;
  for (i=0; i<n-1; i++){
    for (j=i; j<n-1; j++){
      if (a[j]>a[j+1]){
        temp = a[j+1];
        a[j+1] = a[j];
        a[j] = temp;
      }
      else{
      }
    }
  }
}

void QuickSort(int a[], int left, int right){
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
  QuickSort(a, left, i-1);
  QuickSort(a, i+1, right);
}

void Show(int a[], int n){
  int i;
  for (i=0; i<n; i++){
    printf("%d\t", a[i]);
  }
}
int main(){
  int a[3];
  printf ("Please enter 3 integers:\n");
  scanf ("%d%d%d", &a[0], &a[1], &a[2]);
  BubbleSort(a, 3);
  Show(a, 3);
  SelectSort(a, 3);
  Show(a, 3);
  QuickSort(a, 0, 2);
  Show(a, 3);
}
