#include <stdio.h>

int main() {
    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int left = 0;
    int right = n - 1;
    int maxWater = 0;

    while (left < right) {

        int height;

        if (arr[left] < arr[right]) {
            height = arr[left];
        } else {
            height = arr[right];
        }

        int width = right - left;
        int water = height * width;

        if (water > maxWater) {
            maxWater = water;
        }

        // Move the pointer with smaller height
        if (arr[left] < arr[right]) {
            left++;
        } else {
            right--;
        }
    }

    printf("Maximum water = %d\n", maxWater);

    return 0;
}