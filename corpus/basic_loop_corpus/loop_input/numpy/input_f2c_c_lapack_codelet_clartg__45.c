#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *r__ = NULL;
integer i__1;
singlecomplex q__1;
integer i__;
real safmx2;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M elements, adjust for ~0.01s runtime
    static singlecomplex buffer[64 * 1024 * 1024 / sizeof(singlecomplex)]; // Safe compile-time size

    if (sizeof(buffer) < data_size) {
        // Fallback dynamic allocation if static array is too small
        singlecomplex *dynamic_buf = malloc(data_size);
        r__ = (singlecomplex*)dynamic_buf;
    } else {
        r__ = buffer;
    }

    i__1 = data_size / sizeof(singlecomplex);
    safmx2 = 2.0f;

    for (int i = 0; i < i__1; ++i) {
        r__[i].r = (real)(i % 100) / 10.0f;
        r__[i].i = (real)((i + 10) % 100) / 15.0f;
    }

    q__1.r = 0.0f;
    q__1.i = 0.0f;
    i__ = 0;
}