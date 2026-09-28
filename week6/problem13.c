#include <stdio.h>

int main() {
    int price[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(price) / sizeof(price[0]);

    int profit = 0;

    for (int i = 1; i < n; i++) {
        if (price[i] > price[i - 1]) {
            profit += price[i] - price[i - 1];
        }
    }

    printf("Maximum Profit = %d\n", profit);

    return 0;
}