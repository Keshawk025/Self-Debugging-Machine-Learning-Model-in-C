#include <stdio.h>
#include <math.h>
#include "debugger.h"

/* Analyze loss behavior and print warnings */
void analyze_loss(float prev_loss, float curr_loss, int *increase_count) {

    /* Divergence detection */
    if (curr_loss > prev_loss) {
        (*increase_count)++;

        if (*increase_count >= 3) {
            printf("⚠ Warning: Loss increasing continuously\n");
            printf("  Possible cause: Learning rate too high\n");
            printf("  Suggested action: Reduce learning rate\n");
        }
    } else {
        *increase_count = 0;
    }

    /* No-learning detection */
    if (fabs(curr_loss - prev_loss) < 0.0001) {
        printf("⚠ Warning: No significant learning detected\n");
        printf("  Possible cause: Learning rate too low or poor data\n");
    }
}
