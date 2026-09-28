#include <stdio.h>

int main() {
    int arr[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int min = arr[0];
    int maxDiff = arr[1] - arr[0];

    for (int j = 1; j < n; j++) {

        int diff = arr[j] - min;

        if (diff > maxDiff) {
            maxDiff = diff;
        }

        if (arr[j] < min) {
            min = arr[j];
        }
    }

    printf("Maximum Difference = %d", maxDiff);

    return 0;
}