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
JLONG tmp1;
JLONG tmp2;
JLONG tmp10;
JLONG tmp11;
JLONG tmp12;
JLONG z1;
JLONG z2;
JLONG z3;
int ctr;

void init_vars() {
    // Allocate range_limit: map 0..(4*256 + 3) to valid byte indices
    range_limit = (JSAMPLE *)calloc((255 * 4 + 3) + 1, sizeof(JSAMPLE));
    for (int i = 0; i <= (255 * 4 + 3); i++) {
        range_limit[i] = (JSAMPLE)((i >> 2) & 0xFF);
    }

    // Allocate wsptr_base with enough data for ~64MB of input (each iteration uses 6 ints)
    // We want loop to run about 0.01 seconds -> roughly 1e7 iterations
    const size_t total_iterations = 10000000;
    const size_t total_ints = total_iterations * 6;
    wsptr_base = (int *)malloc(total_ints * sizeof(int));
    for (size_t i = 0; i < total_ints; i++) {
        wsptr_base[i] = (int)(i % 8192); // small values to prevent overflow in shifts
    }
    wsptr = wsptr_base;

    // Allocate output_buf: 6 rows per iteration, each row has at least output_col+6 elements
    output_col = 0;
    output_buf = (JSAMPARRAY)malloc(6 * sizeof(JSAMPROW));
    for (int i = 0; i < 6; i++) {
        output_buf[i] = (JSAMPROW)calloc(1, (output_col + 6) * sizeof(JSAMPLE));
    }
}