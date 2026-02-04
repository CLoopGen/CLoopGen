#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long INT32;

JSAMPLE *range_limit;
JSAMPARRAY output_buf;
JDIMENSION output_col;
INT32 tmp0;
INT32 tmp2;
INT32 tmp10;
INT32 tmp12;
int *wsptr;
JSAMPROW outptr;
int ctr;

void init_vars() {
    // Allocate range_limit: needs to cover shifted index range
    // Index calculation uses: >> (13+2+3) = >> 18, and & ((128<<2)*2 - 1) = & (512*2 -1) = & 1023
    // So we need at least 1024 entries in range_limit
    range_limit = calloc(1024, sizeof(JSAMPLE));
    for (int i = 0; i < 1024; i++) {
        range_limit[i] = (JSAMPLE)((i < 256) ? i : 255);
    }

    // output_col should be within bounds of output buffer rows
    output_col = 0;

    // Allocate workspace: wsptr accesses 3 elements per iteration, 3 iterations -> 9 ints
    int *workspace = calloc(16, sizeof(int)); // extra padding
    for (int i = 0; i < 9; i++) {
        workspace[i] = (i % 2 == 0) ? 100 + i : -50 - i;
    }
    wsptr = workspace;

    // Allocate output buffer: 3 rows, each with at least (output_col + 3) columns
    JSAMPLE *output_data = calloc(3 * 8, sizeof(JSAMPLE));
    output_buf = malloc(3 * sizeof(JSAMPROW));
    for (int i = 0; i < 3; i++) {
        output_buf[i] = output_data + i * 8;
    }
}