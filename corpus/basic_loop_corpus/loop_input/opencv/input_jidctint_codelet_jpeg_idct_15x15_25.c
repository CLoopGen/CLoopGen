#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long INT32;

static JSAMPLE *range_limit_data;
static JSAMPROW *output_buf_data;
static int *wsptr_data;

JSAMPARRAY output_buf;
JDIMENSION output_col;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
INT32 tmp14;
INT32 tmp15;
INT32 tmp16;
INT32 tmp20;
INT32 tmp21;
INT32 tmp22;
INT32 tmp23;
INT32 tmp24;
INT32 tmp25;
INT32 tmp26;
INT32 tmp27;
INT32 z1;
INT32 z2;
INT32 z3;
INT32 z4;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

void init_vars() {
    const int DATA_SIZE = 16 * 1024 * 1024; // ~16MB for meaningful timing (~0.01 sec)
    const int ROWS = 15;
    const int COLS = 15;
    const int RANGE_LIMIT_SIZE = (128 << 2) * 2;

    // Allocate range_limit with safe bounds
    range_limit_data = (JSAMPLE *)calloc(RANGE_LIMIT_SIZE, sizeof(JSAMPLE));
    for (int i = 0; i < RANGE_LIMIT_SIZE; i++) {
        range_limit_data[i] = (JSAMPLE)((i & 0xFF) * 0.5); // arbitrary valid values
    }
    range_limit = range_limit_data;

    // Allocate output buffer: 15 rows, each with at least 15+14 elements
    output_buf_data = (JSAMPROW *)calloc(ROWS, sizeof(JSAMPROW));
    for (int i = 0; i < ROWS; i++) {
        output_buf_data[i] = (JSAMPLE *)calloc(COLS + 15, sizeof(JSAMPLE));
    }
    output_buf = output_buf_data;

    // Initialize output_col to a safe starting column (within allocated width)
    output_col = 0;

    // Allocate wsptr: needs at least 8 ints per iteration, 15 iterations -> 120+
    wsptr_data = (int *)calloc(128, sizeof(int));
    for (int i = 0; i < 128; i++) {
        wsptr_data[i] = (i % 2) ? (1 << 10) : -(1 << 10);
    }
    wsptr = wsptr_data;

    // Initialize temporary variables to avoid undefined behavior
    tmp10 = tmp11 = tmp12 = tmp13 = tmp14 = tmp15 = tmp16 = 0;
    tmp20 = tmp21 = tmp22 = tmp23 = tmp24 = tmp25 = tmp26 = tmp27 = 0;
    z1 = z2 = z3 = z4 = 0;
    ctr = 0;
}