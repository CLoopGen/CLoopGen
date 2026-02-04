#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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
INT32 z4;
INT32 z5;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to ensure sufficient runtime

static JSAMPLE *output_buf_data;
static int *wsptr_data;
static JSAMPLE range_limit_data[256 * 4 + 4]; // account for indexing up to (255*4+3)

void init_vars() {
    // Initialize range_limit: maps int values through a clamping function
    for (int i = 0; i < sizeof(range_limit_data); i++) {
        range_limit_data[i] = (JSAMPLE)((i) & 0xFF);
    }
    range_limit = range_limit_data;

    // Allocate and initialize wsptr data (must be at least 8 * 8 = 64 integers for 8 loop iterations)
    wsptr_data = (int *)calloc(DATA_SIZE, sizeof(int));
    for (size_t i = 0; i < DATA_SIZE; i++) {
        wsptr_data[i] = rand() % 2 ? rand() : 0; // mix of zero and non-zero blocks
    }
    wsptr = wsptr_data;

    // Allocate output buffer: 8 rows, each with enough columns
    size_t row_size = (DATA_SIZE / 8 / 8); // ensure we have enough pixel columns
    if (row_size < 8) row_size = 8;
    output_buf_data = (JSAMPLE *)calloc(8 * row_size, sizeof(JSAMPLE));
    output_buf = (JSAMPROW *)malloc(8 * sizeof(JSAMPROW));
    for (int i = 0; i < 8; i++) {
        output_buf[i] = output_buf_data + i * row_size;
    }

    // Initialize column index within bounds
    output_col = 0;
    if (row_size < 8) {
        output_col = 0;
    } else {
        output_col = (row_size - 8) / 2; // center the write window
    }

    // Initialize all scalar temporaries to zero
    tmp0 = tmp1 = tmp2 = tmp3 = 0;
    tmp10 = tmp11 = tmp12 = tmp13 = 0;
    z1 = z2 = z3 = z4 = z5 = 0;
    outptr = NULL;
    ctr = 0;
}