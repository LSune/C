# include 	<stdio.h>

void BubbleSort(int a[], int i){
  int j, k, temp;
  for(j = 0; j < i; j++){
	for(k = 0; k < i - j - 1; k++){
	  if(a[k] <= a[k+1]){
		temp = a[k+1];
		a[k+1] = a[k];
		a[k] = temp;
	  }
	}
  }
}

void main(){
  int i=0, key;
  int a[10];
  printf("Please enter some Integers less than 10(End it by enter #):\n");
  while(scanf("%d", &a[i]) != 0){
	i++;
	if(i >= 10){
	  break;
	}
  }
  getchar();//To catch the unload Char # from the cache pool.
  printf("Please enter the Key to decide the sequence\n");
  scanf("%d", &key);
  BubbleSort(a, i);
  if(key == 1){
	for(key = i - 1; key >= 0; key--){
	  printf("%d\t", a[key]);
	}
  }
  else{
	for(key = 0; key < i; key++){
	  printf("%d\t", a[key]);
	}
  }
  getchar();
}