#include <stdio.h>

int main() {
    int arr[] = {2, 3, -2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxProduct = arr[0];
    int minProduct = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {

        // If current number is negative,
        // maximum and minimum are swapped
        if (arr[i] < 0) {
            int temp = maxProduct;
            maxProduct = minProduct;
            minProduct = temp;
        }

        maxProduct = (arr[i] > maxProduct * arr[i])
                     ? arr[i]
                     : maxProduct * arr[i];

        minProduct = (arr[i] < minProduct * arr[i])
                     ? arr[i]
                     : minProduct * arr[i];

        if (maxProduct > result) {
            result = maxProduct;
        }
    }

    printf("Maximum product: %d\n", result);

    return 0;
}