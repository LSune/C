# include <stdio.h>
# include <stdlib.h>
//# include <alloc.h>

void GetSequence(int * a, int size){
  int i;
  for (i=0; i<size; i++){
    scanf("%d", &a[i]);
  }
}

void Translation(int * a, int size, int trans){
  int temp, i, j=0;
  for(i=size; i<trans+size; i++){
    a[i] = a[j];
    j++;
  }
  a = a[size - trans%size];
}

void Show(int * a, int size){
  int i;
  for(i=0; i<size; i++){
    printf("%d", a[i]);
  }
}

int main(){
  int size, trans;
  int * a;
  printf("Please tell me how many num do you want to input；\n");
  scanf("%d", &size);

  printf("Please tell me the translation num:\n");
  scanf("%d", &trans);
  Show(a, size);
  /**
   * throw the error when facing an error.
   */
  if(a = (int *)malloc(size+trans) == NULL){
    printf("There is an error!\n");
    return 0;
  }
  else{
  }
  GetSequence(a, size);
  Translation(a, size, trans);
  Show(a, size);
  free(a);
}
