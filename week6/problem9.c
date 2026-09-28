#include <stdio.h>

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxRight = arr[n - 1];

    printf("Leaders in the array: ");

    printf("%d ", maxRight);

    for (int i = n - 2; i >= 0; i--) {

        if (arr[i] > maxRight) {
            maxRight = arr[i];
            printf("%d ", maxRight);
        }
    }

    return 0;
}