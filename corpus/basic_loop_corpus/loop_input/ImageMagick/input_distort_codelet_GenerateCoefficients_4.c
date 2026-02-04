#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *arguments;
size_t i;
double inverse[8];

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of data to target ~0.01 sec runtime
    arguments = (double*)aligned_alloc(32, data_size * sizeof(double));
    if (!arguments) exit(1);

    for (size_t idx = 0; idx < data_size; ++idx) {
        arguments[idx] = 1.0 / (idx + 1);
    }
}