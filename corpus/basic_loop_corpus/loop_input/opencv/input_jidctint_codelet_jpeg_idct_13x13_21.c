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
static JSAMPROW outptr_row;
static int *wsptr_global;

JSAMPARRAY output_buf;
JDIMENSION output_col;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
INT32 tmp14;
INT32 tmp15;
INT32 tmp20;
INT32 tmp21;
INT32 tmp22;
INT32 tmp23;
INT32 tmp24;
INT32 tmp25;
INT32 tmp26;
INT32 z1;
INT32 z2;
INT32 z3;
INT32 z4;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

void init_vars() {
    const int range_limit_size = (128 << 2) * 2;
    range_limit_data = (JSAMPLE *)calloc(range_limit_size, sizeof(JSAMPLE));
    for (int i = 0; i < range_limit_size; i++) {
        range_limit_data[i] = (JSAMPLE)((i + 128) & 0xFF);
    }
    range_limit = range_limit_data;

    const int output_rows = 16;
    const int output_cols = 32;
    output_buf_data = (JSAMPROW *)calloc(output_rows, sizeof(JSAMPROW));
    outptr_row = (JSAMPLE *)calloc(output_rows * output_cols, sizeof(JSAMPLE));
    for (int i = 0; i < output_rows; i++) {
        output_buf_data[i] = outptr_row + i * output_cols;
    }
    output_buf = output_buf_data;
    output_col = 0;

    const int wsptr_size = 13 * 8;
    wsptr_data = (int *)calloc(wsptr_size, sizeof(int));
    for (int i = 0; i < wsptr_size; i++) {
        wsptr_data[i] = (i % 251) - 125;
    }
    wsptr_global = wsptr_data;
    wsptr = wsptr_global;

    tmp10 = 0;
    tmp11 = 0;
    tmp12 = 0;
    tmp13 = 0;
    tmp14 = 0;
    tmp15 = 0;
    tmp20 = 0;
    tmp21 = 0;
    tmp22 = 0;
    tmp23 = 0;
    tmp24 = 0;
    tmp25 = 0;
    tmp26 = 0;
    z1 = 0;
    z2 = 0;
    z3 = 0;
    z4 = 0;
    ctr = 0;
}