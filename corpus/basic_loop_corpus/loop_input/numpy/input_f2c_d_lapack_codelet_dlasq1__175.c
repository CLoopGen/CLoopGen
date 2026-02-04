#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *d__;
doublereal *e;
integer i__1;
doublereal d__1;
doublereal d__2;
doublereal d__3;
integer i__;
doublereal sigmx;

void init_vars() {
    i__1 = 10000000;  // 10 million elements, roughly 160 MB for two arrays (assuming 8 bytes per double)

    d__ = (doublereal*)malloc(i__1 * sizeof(doublereal));
    e = (doublereal*)malloc(i__1 * sizeof(doublereal));

    if (!d__ || !e) {
        exit(1);
    }

    for (integer i = 0; i <= i__1; ++i) {
        d__[i] = (i % 2 == 0) ? (i * 0.1) : -(i * 0.1);
        e[i] = ((i + 1) % 3 == 0) ? (i * 0.05) : -(i * 0.05);
    }

    d__1 = 1.0;
    d__2 = 2.0;
    d__3 = 3.0;
    i__ = 1;
    sigmx = 0.0;
}