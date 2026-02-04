#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;

real *e;
integer *info;
integer i__1;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB of float data
    i__1 = (integer)(data_size / sizeof(real));
    e = (real *)aligned_alloc(32, data_size);
    if (!e) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i <= i__1; ++i) {
        e[i] = (real)((i % 7) ? 1.0f : 0.0f); // populate with some zeros and non-zeros
    }

    info = (integer *)malloc(sizeof(integer));
    if (!info) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    *info = 0;
}