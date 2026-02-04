#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

doublecomplex *y;
integer i__1;
integer i__2;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M elements, roughly 1 second for 1M in 0.01s estimate
    i__1 = (integer)(data_size / 16); // Adjust so total loop runs long enough (~0.01 sec)
    if (i__1 > data_size / sizeof(doublecomplex)) {
        i__1 = data_size / sizeof(doublecomplex);
    }

    y = (doublecomplex*)calloc(i__1 + 1, sizeof(doublecomplex));
    if (!y) {
        exit(1);
    }
}