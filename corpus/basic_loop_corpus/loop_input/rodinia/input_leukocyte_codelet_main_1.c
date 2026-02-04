#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
double *t;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB of data (1M doubles), adjust for ~0.01 sec runtime
    t = (double*)calloc(data_size, sizeof(double));
    if (!t) {
        exit(1);
    }
}