#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *m;
doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
doublecomplex z__1;
integer i__;
integer j;
doublereal mul;

void init_vars() {
    // Set matrix dimensions and allocate sufficient data to target ~0.01s runtime
    // Heuristic: use ~16-32 million elements for reasonable performance on modern CPUs
    *m = 4096;
    a_dim1 = *m;
    i__1 = *m;  // j goes from 1 to i__1, inclusive
    mul = 2.5;

    // Allocate array 'a' as a 2D column-major matrix of size m x m
    a = (doublecomplex*)calloc((*m) * (*m), sizeof(doublecomplex));
    if (!a) {
        exit(1);
    }

    // Initialize with non-zero values to make scaling observable
    for (int idx = 0; idx < (*m) * (*m); ++idx) {
        a[idx].r = 1.0 + idx * 0.0001;
        a[idx].i = 0.5 - idx * 0.00005;
    }
}

// One-time global initialization via constructor
static void __attribute__((constructor)) initialize() {
    m = (integer*)malloc(sizeof(integer));
    if (!m) exit(1);
    *m = 0;
    a = NULL;
    init_vars();
}