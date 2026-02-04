#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *e;
integer i__1;
doublereal d__1;
doublereal d__2;
doublereal d__3;
integer i__;
doublereal smax;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data: 2^20 bytes / sizeof(double) ~ 262k elements
    i__1 = (integer)(data_size / sizeof(doublereal));
    
    e = (doublereal*)aligned_alloc(32, data_size);
    if (!e) {
        exit(1);
    }

    for (integer i = 0; i <= i__1; ++i) {
        e[i] = ((doublereal)rand() / RAND_MAX) * 2.0 - 1.0; // Random values in [-1, 1]
    }

    smax = 0.0;
    i__ = 0;
    d__1 = 0.0;
    d__2 = 0.0;
    d__3 = 0.0;
}