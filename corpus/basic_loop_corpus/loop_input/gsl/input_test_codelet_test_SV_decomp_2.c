#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
double lower = 3.14159;
double *a;

void init_vars() {
    const size_t data_size = 268435456; // 256 MB of data
    a = (double*)aligned_alloc(32, data_size);
    if (!a) {
        exit(1);
    }
    for (int j = 0; j < 16; j++) {
        a[j] = 0.0;
    }
}