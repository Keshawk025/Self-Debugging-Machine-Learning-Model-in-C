#include <math.h>
#include "model.h"

/* Calculate Mean Squared Error */
float compute_loss(float w, float x[], float y[], int n) {
    float loss = 0.0;

    for (int i = 0; i < n; i++) {
        float y_pred = w * x[i];
        loss += (y_pred - y[i]) * (y_pred - y[i]);
    }

    return loss / n;
}

/* Calculate gradient for weight update */
float compute_gradient(float w, float x[], float y[], int n) {
    float grad = 0.0;

    for (int i = 0; i < n; i++) {
        grad += (w * x[i] - y[i]) * x[i];
    }

    return grad / n;
}
