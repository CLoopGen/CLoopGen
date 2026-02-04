#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double best_model[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
double *model_out;

void init_vars() {
    size_t data_size = 1 << 20;
    model_out = (double *)aligned_alloc(32, data_size * sizeof(double));
    if (!model_out) {
        exit(1);
    }
    for (size_t i = 0; i < data_size; ++i) {
        model_out[i] = 0.0;
    }
}