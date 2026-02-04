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
INT32 tmp20;
INT32 tmp21;
INT32 tmp22;
INT32 tmp23;
INT32 z1;
INT32 z2;
INT32 z3;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

void init_vars() {
    const int DATA_SIZE = 1024 * 1024; // ~1MB of data for appropriate timing
    range_limit_data = (JSAMPLE *)calloc(DATA_SIZE, sizeof(JSAMPLE));
    output_buf_data = (JSAMPROW *)calloc(16, sizeof(JSAMPROW)); // support up to 16 rows
    wsptr_data = (int *)calloc(16 * 7, sizeof(int));

    if (!range_limit_data || !output_buf_data || !wsptr_data) {
        exit(1);
    }

    for (int i = 0; i < DATA_SIZE; i++) {
        range_limit_data[i] = (JSAMPLE)(i & 0xFF);
    }

    for (int i = 0; i < 16; i++) {
        output_buf_data[i] = &range_limit_data[(i * 128) % (DATA_SIZE - 14)];
    }

    for (int i = 0; i < 16 * 7; i++) {
        wsptr_data[i] = (int)((i * 123456789) % 32768);
    }

    output_buf = output_buf_data;
    output_col = 0;
    wsptr = wsptr_data;
    range_limit = range_limit_data;
}