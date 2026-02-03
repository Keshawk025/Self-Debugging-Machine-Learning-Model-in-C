#include <stdio.h>
#include "model.h"
#include "debugger.h"

#define EPOCHS 30
#define LR 0.1
#define N 10

int main() {

    float x[N] = {1,2,3,4,5,6,7,8,9,10};
    float y[N] = {2,4,6,8,10,12,14,16,18,20};

    float w = 0.0;
    float prev_loss = 1e9;
    float curr_loss;
    int increase_count = 0;

    printf("Starting Self-Debugging Machine Learning Model\n\n");

    for (int epoch = 1; epoch <= EPOCHS; epoch++) {

        float grad = compute_gradient(w, x, y, N);
        w = w - LR * grad;

        curr_loss = compute_loss(w, x, y, N);

        printf("Epoch %d | Weight: %.4f | Loss: %.4f\n",
               epoch, w, curr_loss);

        analyze_loss(prev_loss, curr_loss, &increase_count);

        prev_loss = curr_loss;
        printf("\n");
    }

    printf("Training completed.\n");
    return 0;
}
