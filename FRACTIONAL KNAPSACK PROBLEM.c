#include <stdio.h>

int main() {
    int weight[] = {10, 20, 30};
    int value[] = {60, 100, 120};
    int n = 3;
    int capacity = 50;
    int i, j;

    float ratio[10];

    // Calculate value/weight ratio
    for (i = 0; i < n; i++) {
        ratio[i] = (float)value[i] / weight[i];
    }

    // Bubble sort items by ratio in descending order
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                // Swap ratio
                float tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;

                // Swap weights
                int tempWeight = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = tempWeight;

                // Swap values
                int tempValue = value[j];
                value[j] = value[j + 1];
                value[j + 1] = tempValue;
            }
        }
    }

    float totalValue = 0.0;
    for (i = 0; i < n; i++) {
        if (capacity >= weight[i]) {
            capacity -= weight[i];
            totalValue += value[i];
        } else {
            totalValue += value[i] * ((float)capacity / weight[i]);
            break;
        }
    }

    printf("Maximum value in knapsack = %.2f\n", totalValue);
    return 0;
}

