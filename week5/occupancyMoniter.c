
#include <stdio.h>

int main(void) {
    int R, C;

    printf("Enter number of wards (R) and time slots (C): ");
    scanf("%d %d", &R, &C);

    if (R <= 0 || C <= 0) {
        printf("Invalid number of wards or time slots.\n");
        return 1;
    }

    int bedsPerWard;

    printf("Enter fixed bed capacity per ward: ");
    scanf("%d", &bedsPerWard);

    if (bedsPerWard <= 0) {
        printf("Invalid bed capacity.\n");
        return 1;
    }

    int occupancy[R][C];

    printf("Enter occupied beds matrix (%d x %d):\n", R, C);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &occupancy[i][j]);
        }
    }

    int wardTotals[R];
    int maxWardIdx = 0;
    double maxWardAvg = 0;

    for (int i = 0; i < R; i++) {
        wardTotals[i] = 0;

        for (int j = 0; j < C; j++) {
            wardTotals[i] += occupancy[i][j];
        }

        double avg = (double) wardTotals[i] / C;

        if (i == 0 || avg > maxWardAvg) {
            maxWardAvg = avg;
            maxWardIdx = i;
        }
    }

    // Time slot with maximum total occupancy
    int maxSlotIdx = 0;
    int maxSlotTotal = 0;
    int overallOccupiedSum = 0;

    for (int j = 0; j < C; j++) {
        int slotTotal = 0;

        for (int i = 0; i < R; i++) {
            slotTotal += occupancy[i][j];
        }

        overallOccupiedSum += slotTotal;

        if (j == 0 || slotTotal > maxSlotTotal) {
            maxSlotTotal = slotTotal;
            maxSlotIdx = j;
        }
    }

    printf("\nTotal occupied beds per ward:\n");

    for (int i = 0; i < R; i++) {
        printf("Ward %d: %d\n", i + 1, wardTotals[i]);
    }

    printf("\nWard with highest average occupancy: Ward %d\n",
           maxWardIdx + 1);

    printf("Maximum average occupied beds: %.2f\n", maxWardAvg);

    printf("\nTime slot with maximum occupancy: Slot %d\n",
           maxSlotIdx + 1);

    printf("Maximum occupied beds in a time slot: %d\n",
           maxSlotTotal);

    printf("\nOverall occupied bed readings: %d\n",
           overallOccupiedSum);

    double occupancyPercentage =
        (double) overallOccupiedSum * 100 /
        (R * C * bedsPerWard);

    printf("Overall occupancy percentage: %.2f%%\n",
           occupancyPercentage);

    return 0;
}