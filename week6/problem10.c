#include <stdio.h>

int main() {
    int arr[] = {3, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = n * (n + 1) / 2;
    int arraySum = 0;

    for (int i = 0; i < n; i++) {
        arraySum += arr[i];
    }

    int missing = sum - arraySum;

    printf("Missing number: %d\n", missing);

    return 0;
}