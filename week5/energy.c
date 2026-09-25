
#include <stdio.h>

int main(void) {
    int R, C;

    printf("Enter number of floors (R) and hours (C): ");
    scanf("%d %d", &R, &C);

    double consumption[R][C];

    printf("Enter electricity consumption readings:\n");

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%lf", &consumption[i][j]);
        }
    }

    double threshold;

    printf("Enter average consumption threshold: ");
    scanf("%lf", &threshold);

    double floorTotal[R];
    int maxFloorIdx = 0;

    for (int i = 0; i < R; i++) {
        floorTotal[i] = 0;

        for (int j = 0; j < C; j++) {
            floorTotal[i] += consumption[i][j];
        }

        if (floorTotal[i] > floorTotal[maxFloorIdx]) {
            maxFloorIdx = i;
        }
    }

    // Find hour with highest overall consumption
    int maxHourIdx = 0;
    double maxHourTotal = 0;

    for (int j = 0; j < C; j++) {
        double hourTotal = 0;

        for (int i = 0; i < R; i++) {
            hourTotal += consumption[i][j];
        }

        if (j == 0 || hourTotal > maxHourTotal) {
            maxHourTotal = hourTotal;
            maxHourIdx = j;
        }
    }

    printf("\n--- Floor Statistics ---\n");

    int alertCount = 0;

    for (int i = 0; i < R; i++) {
        double avg = floorTotal[i] / C;

        printf("Floor %d: Total = %.2f, Avg = %.2f",
               i + 1, floorTotal[i], avg);

        if (avg > threshold) {
            printf(" -> [Energy Alert]");
            alertCount++;
        }

        printf("\n");
    }

    printf("\nFloor with highest consumption: Floor %d\n",
           maxFloorIdx + 1);

    printf("Hour with highest consumption: Hour %d (%.2f)\n",
           maxHourIdx + 1, maxHourTotal);

    printf("Total energy alerts: %d\n", alertCount);

    return 0;
}