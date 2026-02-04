#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *model_out;
double best_model[6] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};

void init_vars() {
    model_out = (double*)aligned_alloc(32, 256 * 1024 * 1024);
    if (!model_out) {
        exit(1);
    }
}