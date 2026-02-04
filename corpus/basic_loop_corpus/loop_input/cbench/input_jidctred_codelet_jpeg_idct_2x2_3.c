#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long INT32;

static JSAMPLE *output_buf_data[2];
static JSAMPLE *range_limit_base;
static int *wsptr_data;

JSAMPARRAY output_buf;
JDIMENSION output_col;
INT32 tmp0;
INT32 tmp10;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

void init_vars() {
    // Allocate range_limit: map [-256, 767] to [0, 255] with offset, so we need 1024 entries
    range_limit_base = (JSAMPLE *)calloc(1024, sizeof(JSAMPLE));
    for (int i = 0; i < 1024; i++) {
        int val = i - 256;
        if (val < 0) val = 0;
        if (val > 255) val = 255;
        range_limit_base[i] = (JSAMPLE)val;
    }
    range_limit = range_limit_base;

    // Allocate two rows for output buffer
    JSAMPROW outbuf_row0 = (JSAMPROW)calloc(16, sizeof(JSAMPLE));
    JSAMPROW outbuf_row1 = (JSAMPROW)calloc(16, sizeof(JSAMPLE));
    output_buf_data[0] = outbuf_row0;
    output_buf_data[1] = outbuf_row1;
    output_buf = output_buf_data;

    // Initialize output column within bounds (less than width)
    output_col = 0;

    // Allocate and initialize wsptr_data with 32 elements to allow multiple runs
    wsptr_data = (int *)calloc(32, sizeof(int));
    wsptr_data[0] = 2048;
    wsptr_data[1] = 100;
    wsptr_data[2] = 0;
    wsptr_data[3] = 150;
    wsptr_data[4] = 0;
    wsptr_data[5] = 200;
    wsptr_data[6] = 0;
    wsptr_data[7] = 250;
    wsptr_data[8] = 4096;
    wsptr_data[9] = 300;
    wsptr_data[10] = 0;
    wsptr_data[11] = 350;
    wsptr_data[12] = 0;
    wsptr_data[13] = 400;
    wsptr_data[14] = 0;
    wsptr_data[15] = 450;
    wsptr = wsptr_data;

    // Initialize other scalars
    tmp0 = 0;
    tmp10 = 0;
    ctr = 0;
}