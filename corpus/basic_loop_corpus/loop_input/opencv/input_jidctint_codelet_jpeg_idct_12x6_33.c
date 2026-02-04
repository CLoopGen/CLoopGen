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
    const int RANGE = (128 << 2) * 2;
    const int OUTPUT_ROWS = 6;
    const int WSPTR_SIZE = 8 * 6;
    const int OUTPTR_ROW_SIZE = output_col + 12;

    range_limit_data = calloc(RANGE * 2, sizeof(JSAMPLE));
    if (!range_limit_data) exit(1);
    for (int i = 0; i < RANGE * 2; i++) {
        range_limit_data[i] = (JSAMPLE)((i & (RANGE - 1)) * 255 / (RANGE - 1));
    }

    output_buf_data = malloc(OUTPUT_ROWS * sizeof(JSAMPROW));
    if (!output_buf_data) exit(1);
    for (int i = 0; i < OUTPUT_ROWS; i++) {
        output_buf_data[i] = malloc(OUTPTR_ROW_SIZE * sizeof(JSAMPLE));
        if (!output_buf_data[i]) exit(1);
        for (int j = 0; j < OUTPTR_ROW_SIZE; j++) {
            output_buf_data[i][j] = (JSAMPLE)128;
        }
    }

    wsptr_data = malloc(WSPTR_SIZE * sizeof(int));
    if (!wsptr_data) exit(1);
    for (int i = 0; i < WSPTR_SIZE; i++) {
        wsptr_data[i] = (i % 8) * 1000;
    }

    output_buf = output_buf_data;
    output_col = 0;
    range_limit = range_limit_data;
    wsptr = wsptr_data;
}