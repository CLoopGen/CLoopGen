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
JLONG tmp13;
JLONG z1;
JLONG z2;
JLONG z3;
int ctr;

void init_vars() {
    // Allocate range_limit: needs to cover index up to at least (255*4+3) = 1023
    range_limit = (JSAMPLE*)calloc(1024, sizeof(JSAMPLE));
    for (int i = 0; i < 1024; i++) {
        range_limit[i] = (JSAMPLE)((i >> 2) & 0xFF);
    }

    // Allocate wsptr_base: we access wsptr[0..6], and it's incremented by 7 per loop, total 7 iterations
    wsptr_base = (int*)calloc(7 * 7, sizeof(int));
    for (int i = 0; i < 7 * 7; i++) {
        wsptr_base[i] = (i * 1234567) % 32768;
    }
    wsptr = wsptr_base;

    // Allocate output_buf: array of 7 rows, each row accessed with +output_col and indices 0..6
    output_buf = (JSAMPARRAY)calloc(7, sizeof(JSAMPROW));
    for (int i = 0; i < 7; i++) {
        output_buf[i] = (JSAMPROW)calloc(16, sizeof(JSAMPLE)); // extra space for safety
    }

    // Set output_col within bounds so that outptr[6] is valid
    output_col = 0;

    // Initialize temp variables to zero (they are overwritten in loop, but initialize for determinism)
    tmp0 = tmp1 = tmp2 = tmp10 = tmp11 = tmp12 = tmp13 = z1 = z2 = z3 = 0;
    ctr = 0;
}