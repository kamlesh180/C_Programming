#include <stdio.h>

int main() {
    int arr[] = {2, 2, 1, 1, 1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int candidate = 0;
    int count = 0;

    // Find the candidate
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
        }

        if (arr[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Verify the candidate
    count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) {
            count++;
        }
    }

    if (count > n / 2) {
        printf("Majority Element = %d", candidate);
    } else {
        printf("No Majority Element");
    }

    return 0;
}