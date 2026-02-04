#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t order = 10;
size_t i;
double beta = 1.5;
double q[11] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
size_t k;

void init_vars() {
    order = 10;
    beta = 1.5;
    for (i = 0; i < 11; ++i) {
        q[i] = (double)i;
    }
}