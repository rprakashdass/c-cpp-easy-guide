#include <stdio.h>

void radix(int ar[],int n){
    int k = 0, min = ar[0];
    for(int i =0;i<n;i++)
        if(ar[i] > min)
            min = ar[i];
    while(min > 0){
        min = min / 10;
        k++;
    }
    int c = 0;
    int d = 1,digit;
    int count[n],temp[n];
    while( k > 0){
       
        for(int i = 0;i < 10;i++)
            count[i] = 0;
            
        for(int i = 0;i<n;i++){
            digit = (ar[i] / d) % 10;
            count[digit]++;
        }
        
        for(int i = 1;i < 10;i++)
            count[i] += count[i-1];
        
        for(int j = n-1;j>=0;j--)
            temp[--count[(ar[j] / d) % 10]] = ar[j];
    
        for(int i = 0;i < n;i++)
            ar[i] = temp[i];
            
    d = d*10;
     k--;
    }
}


int main() {
    int arr[] = {23, 1, 44, 2, 3, 2233, 122, 90, 65};
    int n = sizeof(arr) / sizeof(arr[0]);
    radix(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

