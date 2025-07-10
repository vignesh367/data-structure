#include <stdio.h>
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}
int main() {
    int arr[] = {5, 2, 4, 6, 1, 3}, n = 6;
    insertionSort(arr, n);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
