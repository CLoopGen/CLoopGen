#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef float real;
typedef int integer;

real *z__;
integer i__1;
integer i0;
integer i4;
integer ipn4;
real temp;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB of data (~0.01 sec on modern CPU)
    z__ = (real*)aligned_alloc(32, data_size);
    
    if (!z__) {
        exit(1);
    }

    for (size_t i = 0; i < data_size / sizeof(real); ++i) {
        z__[i] = (real)(i % 1000) + 1.0f;
    }

    i0 = 1;
    i__1 = (data_size / sizeof(real)) - 8;
    ipn4 = (data_size / sizeof(real)) + 4;

    temp = 0.0f;
    i4 = 0;
}