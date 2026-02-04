#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long INT32;

static JSAMPLE *range_limit_data;
static JSAMPROW *output_buf_data;
static int *wsptr_data;
static JSAMPLE dcval_init = 128;

JSAMPARRAY output_buf;
JDIMENSION output_col;
INT32 tmp0;
INT32 tmp2;
INT32 tmp10;
INT32 tmp12;
INT32 z1;
INT32 z2;
INT32 z3;
INT32 z4;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

void init_vars() {
    const int DATA_SIZE = 16 * 1024 * 1024; // ~16MB to target ~0.01s runtime

    range_limit_data = (JSAMPLE*)calloc(256 * 4 + 4, sizeof(JSAMPLE));
    for (int i = 0; i < 256 * 4 + 4; i++) {
        range_limit_data[i] = (JSAMPLE)((i & (255 * 4 + 3)) >> 2);
    }
    range_limit = range_limit_data;

    wsptr_data = (int*)calloc(DATA_SIZE, sizeof(int));
    wsptr = wsptr_data;

    output_buf_data = (JSAMPROW*)calloc(4, sizeof(JSAMPROW));
    for (int i = 0; i < 4; i++) {
        output_buf_data[i] = (JSAMPLE*)calloc(1024, sizeof(JSAMPLE));
    }
    output_buf = output_buf_data;

    output_col = 0;

    for (int i = 0; i < DATA_SIZE / 8; i++) {
        int base = i * 8;
        wsptr_data[base + 0] = 256;
        wsptr_data[base + 1] = rand() % 3 - 1;
        wsptr_data[base + 2] = rand() % 3 - 1;
        wsptr_data[base + 3] = rand() % 3 - 1;
        wsptr_data[base + 4] = 256;
        wsptr_data[base + 5] = rand() % 3 - 1;
        wsptr_data[base + 6] = rand() % 3 - 1;
        wsptr_data[base + 7] = rand() % 3 - 1;
    }
}