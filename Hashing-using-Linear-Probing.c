#include <stdio.h>
#define SIZE 10
int hash[SIZE];
void insert(int key) {
    int index = key % SIZE;
    while (hash[index] != -1) {
        index = (index + 1) % SIZE;
    }
    hash[index] = key;
}
int main() {
    for (int i = 0; i < SIZE; i++) hash[i] = -1;
    int arr[] = {23, 43, 13, 27};
    for (int i = 0; i < 4; i++) insert(arr[i]);
    for (int i = 0; i < SIZE; i++) printf("%d ", hash[i]);
    return 0;
}

