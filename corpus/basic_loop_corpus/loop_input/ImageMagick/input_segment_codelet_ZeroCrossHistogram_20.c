#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *second_derivative;
short *crossings;
ssize_t i;
ssize_t parity;

void init_vars() {
    size_t data_size = 256 * 1024 * 1024; // 256 MB total data
    size_t count = data_size / sizeof(double);
    if (count > 256) count = 256;

    second_derivative = (double *)calloc(count, sizeof(double));
    crossings = (short *)calloc(count, sizeof(short));

    for (size_t idx = 0; idx < count; idx++) {
        if (idx % 2 == 0)
            second_derivative[idx] = -1.0;
        else
            second_derivative[idx] = 1.0;
    }

    i = 0;
    parity = 0;
}

static void constructor_init() __attribute__((constructor));
static void constructor_init() {
    init_vars();
}