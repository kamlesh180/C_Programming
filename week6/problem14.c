#include <stdio.h>

int main() {
    int arr[] = {100, 4, 200, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int longest = 0;

    for (int i = 0; i < n; i++) {
        int count = 1;
        int current = arr[i];

        // Find consecutive numbers
        while (1) {
            int found = 0;

            for (int j = 0; j < n; j++) {
                if (arr[j] == current + 1) {
                    found = 1;
                    break;
                }
            }

            if (found) {
                current++;
                count++;
            } else {
                break;
            }
        }

        if (count > longest) {
            longest = count;
        }
    }

    printf("Longest consecutive sequence length = %d\n", longest);

    return 0;
}