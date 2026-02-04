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
INT32 tmp2;
INT32 tmp10;
INT32 tmp12;
INT32 z1;
INT32 z2;
INT32 z3;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01 sec runtime

static int *wsptr_data = NULL;
static JSAMPLE *range_limit_data = NULL;
static JSAMPARRAY output_buf_data = NULL;

void init_vars() {
    // Allocate wsptr: accessed as wsptr[0..3], advanced by 4 each iteration, 4 iterations -> needs 16 ints
    wsptr_data = (int*)calloc(16, sizeof(int));
    for (int i = 0; i < 16; i++) {
        wsptr_data[i] = (i % 7) * 1000; // arbitrary non-zero initialization
    }
    wsptr = wsptr_data;

    // Allocate range_limit: indexed with mask ((128 << 2) * 2 - 1) = 1023
    range_limit_data = (JSAMPLE*)malloc(1024 * sizeof(JSAMPLE));
    for (int i = 0; i < 1024; i++) {
        range_limit_data[i] = (JSAMPLE)((i * 31) % 256);
    }
    range_limit = range_limit_data;

    // Allocate output_buf: 4 rows, each row has at least output_col+4 elements
    output_col = 0; // Ensure no offset issues
    output_buf_data = (JSAMPARRAY)calloc(4, sizeof(JSAMPROW));
    for (int i = 0; i < 4; i++) {
        output_buf_data[i] = (JSAMPROW)calloc(output_col + 4, sizeof(JSAMPLE));
    }
    output_buf = output_buf_data;
}