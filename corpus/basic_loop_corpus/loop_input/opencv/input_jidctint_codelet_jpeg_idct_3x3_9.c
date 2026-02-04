#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long JLONG;

JSAMPLE *range_limit;
int *wsptr_base;
int *wsptr;
JSAMPROW outptr;
JSAMPARRAY output_buf;
JDIMENSION output_col;
JLONG tmp0;
JLONG tmp2;
JLONG tmp10;
JLONG tmp12;
int ctr;

void init_vars() {
    // Allocate range_limit: needs to cover at least 0 to (255*4+3) = 1023
    range_limit = (JSAMPLE *)calloc(1024, sizeof(JSAMPLE));
    for (int i = 0; i < 1024; i++) {
        range_limit[i] = (JSAMPLE)((i >> 2) & 0xFF);
    }

    // We want the loop to run ~3 iterations and access wsptr[0], wsptr[1], wsptr[2]
    // So allocate enough data for 3 iterations * 3 elements per iteration = 9 integers
    wsptr_base = (int *)malloc(9 * sizeof(int));
    wsptr = wsptr_base;
    for (int i = 0; i < 9; i++) {
        wsptr_base[i] = (i % 7) * 1000; // Small values to avoid overflow in fixed-point arithmetic
    }

    // output_buf has 3 rows (indexed by ctr from 0 to 2)
    output_buf = (JSAMPARRAY)malloc(3 * sizeof(JSAMPROW));
    for (int i = 0; i < 3; i++) {
        output_buf[i] = (JSAMPROW)malloc(16 * sizeof(JSAMPLE)); // Each row has at least 3 elements
    }

    output_col = 0; // Ensure outptr[0], outptr[1], outptr[2] are valid
}

// Initialize variables to prevent undefined behavior
static void __attribute__((constructor)) initialize() {
    init_vars();
}