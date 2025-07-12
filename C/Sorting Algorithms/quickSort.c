#include <stdio.h>

int partition(int a[], int l, int r) {
    int pivot = a[l];
    int i = l + 1;
    int j = r;

    while (i <= j) {

        while (i <= j && a[i] < pivot)
            i++;

        while (j >= i && a[j] > pivot)
            j--;

        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[l];
    a[l] = a[j];
    a[j] = temp;

    return j;
}

void quicksort(int arr[], int l, int r) {
    if (l < r) {
        int pos = partition(arr, l, r);
        quicksort(arr, l, pos - 1);
        quicksort(arr, pos + 1, r);
    }
}

int main() {
    int arr[] = {23, 1, 44, 2,3,2233,122,90, 65};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}

