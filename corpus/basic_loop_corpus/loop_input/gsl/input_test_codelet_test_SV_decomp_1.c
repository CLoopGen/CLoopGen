#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int i;
double carry;
double lower;
double upper;
double *a;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime
    a = aligned_alloc(32, data_size);
    if (!a) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size / sizeof(double); ++idx) {
        a[idx] = 0.5;
    }

    i = data_size / sizeof(double) - 1;
    if (i > 9) {
        i = 9;
    }
    carry = 1.0;
    lower = 0.0;
    upper = 1.0;
}