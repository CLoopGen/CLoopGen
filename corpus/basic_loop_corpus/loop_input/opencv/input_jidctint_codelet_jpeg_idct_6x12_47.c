#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long INT32;

// Define arrays and buffers with sufficient size
static JSAMPLE g_range_limit[1024];
static int g_wsptr_data[12 * 6]; // 12 iterations, 6 ints each
static JSAMPLE g_output_buf_data[12][16]; // 12 rows, at least 6 columns
static JSAMPROW g_output_buf_rows[12];

// External variables
JSAMPARRAY output_buf = g_output_buf_rows;
JDIMENSION output_col = 0;
INT32 tmp10, tmp11, tmp12;
INT32 tmp20, tmp21, tmp22;
INT32 z1, z2, z3;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit = g_range_limit;
int ctr;

void init_vars() {
    // Initialize range_limit with identity mapping in valid range
    for (int i = 0; i < 1024; i++) {
        g_range_limit[i] = (JSAMPLE)((i & 255));
    }

    // Initialize wsptr data with non-zero values to ensure computation happens
    for (int i = 0; i < 12 * 6; i++) {
        g_wsptr_data[i] = (i * 17 + 1) % 1000 - 500; // Signed values in reasonable range
    }
    wsptr = g_wsptr_data;

    // Initialize output buffer rows
    for (int i = 0; i < 12; i++) {
        g_output_buf_rows[i] = g_output_buf_data[i];
    }

    // Ensure output_col is within bounds (so + output_col doesn't overflow)
    output_col = 0; // so that access to indices 0..5 is valid
}