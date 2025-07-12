#include<stdio.h>

void shellSort(int arr[], int n) { 
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        for (int i = gap; i < n; i += 1) 
        { 
            int temp = arr[i]; 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
            arr[j] = temp; 
        } 
    } 
} 
  
int main() {
    int arr[] = {23, 1, 44, 2, 3, 22,33, 122, 90, 65};
    int n = 10;
    shellSort(arr, n);
    for(int i = 0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
