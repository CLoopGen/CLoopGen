#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long INT32;

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
INT32 z1;
INT32 z2;
INT32 z3;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

#define DATA_SIZE (16 << 20)  // ~16MB of data to target ~0.01s runtime

static JSAMPLE *output_buffer_pool = NULL;
static int *wsdata = NULL;
static JSAMPLE *range_limit_data = NULL;

void init_vars() {
    // Allocate range_limit: covers index range with mask ((128 << 2) * 2 - 1) = 1023
    range_limit_data = (JSAMPLE *)calloc(1024, sizeof(JSAMPLE));
    for (int i = 0; i < 1024; i++) {
        range_limit_data[i] = (JSAMPLE)((i & 255));
    }
    range_limit = range_limit_data;

    // Allocate workspace data: at least 4 iterations * 8 ints per step = 32 ints
    wsdata = (int *)malloc(64 * sizeof(int));
    for (int i = 0; i < 64; i++) {
        wsdata[i] = (i % 251) - 125;  // small signed values
    }
    wsptr = wsdata;

    // Allocate output buffer pool: 4 rows, each row has enough space for col access
    output_col = 0;
    output_buffer_pool = (JSAMPLE *)calloc(4 * 8, sizeof(JSAMPLE));
    output_buf = (JSAMPROW *)malloc(4 * sizeof(JSAMPROW));
    for (int i = 0; i < 4; i++) {
        output_buf[i] = &output_buffer_pool[i * 8];
    }

    // Initialize scalars
    tmp0 = tmp1 = tmp2 = tmp3 = 0;
    tmp10 = tmp11 = tmp12 = tmp13 = 0;
    z1 = z2 = z3 = 0;
    ctr = 0;
    outptr = output_buf[0];
}