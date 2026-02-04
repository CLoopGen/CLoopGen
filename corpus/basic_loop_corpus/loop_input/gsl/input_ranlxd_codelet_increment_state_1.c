#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double one_bit = 1.0;
int k = 0;
int kmax = 8388608; // Ensures loop runs enough iterations (~12 * 8e6 = 100M operations, ~0.01 sec)
double _usr_y1 = 0.0;
double y2 = 0.0;
double y3 = 0.0;
double carry = 0.0;

double *xdbl = NULL;

void init_vars() {
    size_t array_size = 12 + 12; // Need at least 12 elements (indexed 0..11), plus padding for safety
    xdbl = (double *)aligned_alloc(32, array_size * sizeof(double));
    if (!xdbl) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < array_size; ++i) {
        xdbl[i] = (double)(i % 7) * 0.125;
    }

    k = 0;
    kmax = 8388608;
    _usr_y1 = 0.0;
    y2 = 0.0;
    y3 = 0.0;
    carry = 0.0;
    one_bit = 1.0;
}