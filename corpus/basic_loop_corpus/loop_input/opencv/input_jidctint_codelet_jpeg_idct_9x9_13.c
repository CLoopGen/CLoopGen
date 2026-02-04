#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long INT32;

// External variables as declared in the loop
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
INT32 tmp14;
INT32 z1;
INT32 z2;
INT32 z3;
INT32 z4;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

#define DATA_SIZE (16 << 20)  // ~16MB of data for sufficient runtime

static JSAMPLE *output_buf_data = NULL;
static JSAMPROW *output_buf_rows = NULL;
static int *wsptr_data = NULL;
static JSAMPLE *range_limit_data = NULL;

void init_vars() {
    // Initialize range_limit: needs to cover shifted index range
    // The expression uses: >> (13+2+3) = >> 18, and & ((128<<2)*2 - 1) = & 1023
    // So we need at least 1024 entries
    range_limit_data = calloc(1024, sizeof(JSAMPLE));
    for (int i = 0; i < 1024; i++) {
        range_limit_data[i] = (JSAMPLE)((i + 128) & 0xFF);
    }
    range_limit = range_limit_data;

    // Allocate large block for output samples
    output_buf_data = malloc(DATA_SIZE);
    if (!output_buf_data) exit(1);

    // Each row is 9 elements wide (since loop runs 9 times, accesses [0..8])
    size_t row_size = 9 * sizeof(JSAMPLE);
    int num_rows = DATA_SIZE / row_size;
    if (num_rows < 9) exit(1);  // Need at least 9 rows

    output_buf_rows = malloc(num_rows * sizeof(JSAMPROW));
    if (!output_buf_rows) exit(1);

    for (int i = 0; i < num_rows; i++) {
        output_buf_rows[i] = &output_buf_data[i * 9];
    }
    output_buf = output_buf_rows;
    output_col = 0;  // Ensure within bounds

    // wsptr points to array of 8 * 9 = 72 integers (9 iterations, 8 per step)
    wsptr_data = calloc(72, sizeof(int));
    if (!wsptr_data) exit(1);

    for (int i = 0; i < 72; i++) {
        wsptr_data[i] = (i % 7) ? (1000 + i * 17) : 0;
    }
    wsptr = wsptr_data;

    // Initialize temp variables to avoid undefined behavior
    tmp0 = tmp1 = tmp2 = tmp3 = 0;
    tmp10 = tmp11 = tmp12 = tmp13 = tmp14 = 0;
    z1 = z2 = z3 = z4 = 0;
    ctr = 0;
    outptr = output_buf[0];
}