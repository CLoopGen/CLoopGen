#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
double lower = 3.14159;
double *a;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256 MB
    a = (double*)aligned_alloc(32, data_size);
    if (!a) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size / sizeof(double); ++idx) {
        a[idx] = 0.0;
    }
    lower = 1.0;
}