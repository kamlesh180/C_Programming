#include <stdio.h>

int main() {
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int totalSum = 0;
    int leftSum = 0;

    // Calculate total sum
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    // Find equilibrium index
    for (int i = 0; i < n; i++) {

        int rightSum = totalSum - leftSum - arr[i];

        if (leftSum == rightSum) {
            printf("Equilibrium index: %d\n", i);
            return 0;
        }

        leftSum += arr[i];
    }

    printf("No equilibrium index found\n");

    return 0;
}