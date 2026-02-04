#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long INT32;

// External variables
JSAMPARRAY output_buf;
JDIMENSION output_col;
INT32 tmp0;
INT32 tmp2;
INT32 tmp10;
INT32 tmp12;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01 sec runtime

static JSAMPLE *output_buf_data;
static int *wsptr_data;
static JSAMPLE *range_limit_data;

void init_vars() {
    // Allocate range_limit: needs to cover shifted index range
    // Index calculation uses: >> (13+2+3) = >> 18, and & ((128<<2)*2 - 1) = & 1023
    // So we need range_limit[0..1023] at least, but allocate extra for safety
    range_limit_data = malloc(2048 * sizeof(JSAMPLE));
    for (int i = 0; i < 2048; i++) {
        range_limit_data[i] = (JSAMPLE)((i > 255) ? 255 : (i < 0) ? 0 : i);
    }
    range_limit = range_limit_data;

    // Allocate workspace data: loop runs 6 iterations, each does wsptr += 3
    // So we need 6 * 3 = 18 ints
    wsptr_data = malloc(18 * sizeof(int));
    for (int i = 0; i < 18; i++) {
        wsptr_data[i] = (rand() % 1024) - 512; // Small values to avoid overflow
    }
    wsptr = wsptr_data;

    // Allocate output buffer: 6 rows, each row must accommodate output_col + at least 3 elements
    // We set output_col = 0 to ensure access within bounds
    output_col = 0;

    output_buf_data = malloc(6 * 3 * sizeof(JSAMPLE));
    output_buf = malloc(6 * sizeof(JSAMPROW));
    for (int i = 0; i < 6; i++) {
        output_buf[i] = &output_buf_data[i * 3];
    }

    // Initialize temp variables to zero (will be overwritten in loop)
    tmp0 = tmp2 = tmp10 = tmp12 = 0;

    // Initialize outptr to NULL (will be assigned in loop)
    outptr = NULL;

    // Initialize ctr to 0 (loop counter)
    ctr = 0;
}