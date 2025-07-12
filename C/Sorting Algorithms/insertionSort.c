#include<stdio.h>

void shell(int ar[],int n){
    int j = 0;
    for(int i = 1;i < n;i++){
      int temp = ar[i];
      j = i-1;
      while(temp < ar[j] && j >= 0){
          ar[j+1] = ar[j];
          j--;
      }
     ar[j+1] = temp;
    for (int i = 0; i < n; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");
    }
}

int main() {
    int arr[] = {23, 1, 44, 2, 3, 22,33, 122, 90, 65};
    int n = 10;
    shell(arr, n);
    return 0;
}

