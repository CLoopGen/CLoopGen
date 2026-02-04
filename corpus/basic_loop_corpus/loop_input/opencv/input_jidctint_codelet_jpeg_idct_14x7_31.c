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
static JSAMPLE **output_buf_data;
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
INT32 tmp16;
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
    const int RANGE = (128 << 2) * 2;
    const int DATA_SIZE = 1 << 20;
    const int NUM_ROWS = 7;
    const int ROW_WIDTH = 16; // At least 14 used in loop (index up to 13)

    range_limit_data = (JSAMPLE*)calloc(RANGE, sizeof(JSAMPLE));
    for (int i = 0; i < RANGE; i++) {
        range_limit_data[i] = (JSAMPLE)((i + 128) & 0xFF);
    }

    output_buf_data = (JSAMPARRAY)calloc(NUM_ROWS, sizeof(JSAMPROW));
    outptr_row = (JSAMPROW)calloc(NUM_ROWS * ROW_WIDTH, sizeof(JSAMPLE));
    for (int i = 0; i < NUM_ROWS; i++) {
        output_buf_data[i] = outptr_row + i * ROW_WIDTH;
    }

    wsptr_data = (int*)calloc(DATA_SIZE, sizeof(int));
    for (int i = 0; i < DATA_SIZE / 8; i++) {
        for (int j = 0; j < 8; j++) {
            wsptr_data[i * 8 + j] = ((i + 1) * (j + 1)) ^ 0xABCDEF;
        }
    }

    output_buf = output_buf_data;
    range_limit = range_limit_data;
    wsptr = wsptr_data;
    output_col = 0;
}