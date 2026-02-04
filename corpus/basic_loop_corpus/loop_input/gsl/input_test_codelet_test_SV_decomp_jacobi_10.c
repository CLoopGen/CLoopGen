#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
double lower = 3.14159;
double *a;

void init_vars() {
    size_t data_size = 256 * 1024 * 1024; // 256 MB
    a = (double*)aligned_alloc(32, data_size);
    if (!a) {
        exit(1);
    }
    for (int j = 0; j < 16; j++) {
        a[j] = 0.0;
    }
}