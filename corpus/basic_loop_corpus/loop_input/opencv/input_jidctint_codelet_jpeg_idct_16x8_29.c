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
INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
INT32 tmp3;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
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
    const int DATA_SIZE = 8 * 1024 * 1024; // ~8MB of working data
    const int ROWS = 8;
    const int COLS = 16;
    const int RANGE_LIMIT_SIZE = (128 << 2) * 2;

    // Allocate range_limit with proper bounds
    range_limit_data = (JSAMPLE*)calloc(RANGE_LIMIT_SIZE, sizeof(JSAMPLE));
    for (int i = 0; i < RANGE_LIMIT_SIZE; ++i) {
        range_limit_data[i] = (JSAMPLE)((i & (RANGE_LIMIT_SIZE - 1)) % 256);
    }
    range_limit = range_limit_data;

    // Allocate output buffer: 8 rows, each with at least 16+output_col elements
    output_col = 0; // Ensure no offset overflow
    output_buf_data = (JSAMPROW*)calloc(ROWS, sizeof(JSAMPROW));
    for (int i = 0; i < ROWS; ++i) {
        output_buf_data[i] = (JSAMPLE*)calloc(COLS, sizeof(JSAMPLE));
    }
    output_buf = output_buf_data;

    // Allocate wsptr: 8x8 block processing, loop runs 8 times, so need 64 integers
    wsptr_data = (int*)calloc(64, sizeof(int));
    for (int i = 0; i < 64; ++i) {
        wsptr_data[i] = (i * 17) % 1024;
    }
    wsptr = wsptr_data;

    // Initialize temporary variables to zero
    tmp0 = tmp1 = tmp2 = tmp3 = 0;
    tmp10 = tmp11 = tmp12 = tmp13 = 0;
    tmp20 = tmp21 = tmp22 = tmp23 = tmp24 = tmp25 = tmp26 = tmp27 = 0;
    z1 = z2 = z3 = z4 = 0;
    ctr = 0;
}