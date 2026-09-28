#include <stdio.h>

int main() {
    int arr[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Duplicate elements: ");

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            if (arr[i] == arr[j]) {
                printf("%d ", arr[i]);
                break;
            }
        }
    }

    return 0;
}