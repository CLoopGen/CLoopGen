#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef int DCTELEM;
typedef long INT32;

JSAMPARRAY output_buf;
JDIMENSION output_col;
DCTELEM tmp0;
DCTELEM tmp1;
DCTELEM tmp2;
DCTELEM tmp3;
DCTELEM tmp4;
DCTELEM tmp5;
DCTELEM tmp6;
DCTELEM tmp7;
DCTELEM tmp10;
DCTELEM tmp11;
DCTELEM tmp12;
DCTELEM tmp13;
DCTELEM z5;
DCTELEM z10;
DCTELEM z11;
DCTELEM z12;
DCTELEM z13;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

#define DATA_SIZE (1 << 20)  // ~1MB of data

static JSAMPLE *output_buffer_storage;
static int *wsptr_storage;
static JSAMPLE *range_limit_storage;

void init_vars() {
    // Allocate range limit: needs to cover index up to (255*4+3) = 1023
    range_limit_storage = (JSAMPLE*)calloc(1024, sizeof(JSAMPLE));
    for (int i = 0; i < 256; i++) {
        range_limit_storage[i] = (JSAMPLE)i;
    }
    for (int i = 256; i < 1024; i++) {
        range_limit_storage[i] = 255;
    }
    range_limit = range_limit_storage;

    // Allocate workspace: we need at least 8 * 8 = 64 values for 8 iterations with 8 wsptr[0..7]
    wsptr_storage = (int*)malloc(64 * sizeof(int));
    for (int i = 0; i < 64; i++) {
        wsptr_storage[i] = (i % 8 == 0) ? 1024 : ((i % 4) ? 1 : 0); // non-zero only on DC-like and few AC
    }
    wsptr = wsptr_storage;

    // Allocate output buffer: 8 rows, each with at least output_col + 8 samples
    output_col = 0;
    output_buffer_storage = (JSAMPLE*)calloc(8 * 16, sizeof(JSAMPLE));
    output_buf = (JSAMPROW*)malloc(8 * sizeof(JSAMPROW));
    for (int i = 0; i < 8; i++) {
        output_buf[i] = &output_buffer_storage[i * 16];
    }

    // Initialize loop counters
    ctr = 0;
}