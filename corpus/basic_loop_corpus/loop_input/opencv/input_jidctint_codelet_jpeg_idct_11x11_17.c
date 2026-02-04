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
INT32 tmp20;
INT32 tmp21;
INT32 tmp22;
INT32 tmp23;
INT32 tmp24;
INT32 tmp25;
INT32 z1;
INT32 z2;
INT32 z3;
INT32 z4;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

void init_vars() {
    const int RANGE = 512;
    const int ROWS = 11;
    const int COLS = 8;
    const int DATA_SIZE = 16 * 1024 * 1024;
    const int WSPTR_SIZE = (DATA_SIZE / (ROWS * COLS)) * COLS;

    range_limit_data = (JSAMPLE *)calloc(RANGE, sizeof(JSAMPLE));
    output_buf_data = (JSAMPROW *)calloc(ROWS, sizeof(JSAMPROW));
    wsptr_data = (int *)calloc(WSPTR_SIZE, sizeof(int));

    for (int i = 0; i < RANGE; i++) {
        range_limit_data[i] = (JSAMPLE)((i + 256) & 0xFF);
    }

    for (int i = 0; i < ROWS; i++) {
        output_buf_data[i] = (JSAMPLE *)calloc(COLS * 2, sizeof(JSAMPLE));
        for (int j = 0; j < COLS * 2; j++) {
            output_buf_data[i][j] = (JSAMPLE)(j * i + 1);
        }
    }

    for (int i = 0; i < WSPTR_SIZE; i++) {
        wsptr_data[i] = (i * 17) % 1000 - 500;
    }

    output_buf = output_buf_data;
    output_col = 0;
    wsptr = wsptr_data;
    range_limit = range_limit_data;
}