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

doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
doublecomplex z__1;
integer i__;
integer j;
integer k3;
integer k4;
doublereal mul;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // Based on typical performance, aim for ~64M elements total
    a_dim1 = 8192;
    i__1 = 8192;  // j from 1 to 8192
    k3 = 8192;
    k4 = 8192;
    mul = 2.5;

    // Allocate 2D array as contiguous memory (row-major assumed)
    a = (doublecomplex*)calloc(a_dim1 * i__1, sizeof(doublecomplex));
    if (!a) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize data to avoid undefined behavior
    for (int idx = 0; idx < a_dim1 * i__1; ++idx) {
        a[idx].r = 1.0 + idx * 0.0001;
        a[idx].i = 0.5 - idx * 0.00005;
    }
}