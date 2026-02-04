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
    const int data_size = 16 * 1024 * 1024; // ~16MB to target ~0.01s runtime
    const int row_count = 14;
    const int row_width = 32;
    int i, j;

    // Allocate range_limit: maps 0-511 (centered at 256) to valid byte values
    range_limit_data = (JSAMPLE *)calloc(512 + 256, sizeof(JSAMPLE));
    range_limit = range_limit_data + 256;
    for (i = -256; i < 256; i++) {
        range_limit[i] = (i < 0) ? 0 : ((i > 255) ? 255 : (JSAMPLE)i);
    }

    // Allocate output buffer: 14 rows, each with row_width elements
    output_buf_data = (JSAMPARRAY)calloc(row_count, sizeof(JSAMPROW));
    for (i = 0; i < row_count; i++) {
        output_buf_data[i] = (JSAMPROW)calloc(row_width, sizeof(JSAMPLE));
    }
    output_buf = output_buf_data;
    output_col = 0; // Ensure within row_width bounds

    // Allocate workspace: 14 iterations * 8 ints per iteration
    wsptr_data = (int *)calloc(data_size, sizeof(int));
    for (i = 0; i < data_size; i++) {
        wsptr_data[i] = (rand() % 2048) - 1024; // Small centered values
    }
    wsptr_global = wsptr_data;
    wsptr = wsptr_global;

    // Initialize other scalar variables to zero or safe defaults
    tmp10 = 0;
    tmp11 = 0;
    tmp12 = 0;
    tmp13 = 0;
    tmp14 = 0;
    tmp15 = 0;
    tmp16 = 0;
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

    outptr = output_buf[0];
}