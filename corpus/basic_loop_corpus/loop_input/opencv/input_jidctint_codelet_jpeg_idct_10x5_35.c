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
static int g_wsptr_data[40]; // 5 iterations * 8 ints per iteration
static JSAMPLE g_output_buf_rows[5][20]; // 5 rows, each with at least 10+9 elements
static JSAMPROW g_output_buf[5];

// External variables
JSAMPARRAY output_buf = g_output_buf;
JDIMENSION output_col = 0;
INT32 tmp10, tmp11, tmp12, tmp13, tmp14;
INT32 tmp20, tmp21, tmp22, tmp23, tmp24;
INT32 z1, z2, z3, z4;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit = g_range_limit;
int ctr;

void init_vars() {
    // Initialize range_limit with valid values (clamp to 0-255 range)
    for (int i = 0; i < 1024; i++) {
        g_range_limit[i] = (JSAMPLE)((i & 511) > 255 ? 255 : (i & 511));
    }

    // Initialize wsptr data with non-zero values to ensure computation happens
    for (int i = 0; i < 40; i++) {
        g_wsptr_data[i] = (i * 17 + 1) * ((i % 2) ? -1 : 1);
    }
    wsptr = g_wsptr_data;

    // Initialize output_buf rows
    for (int i = 0; i < 5; i++) {
        g_output_buf[i] = g_output_buf_rows[i];
        for (int j = 0; j < 20; j++) {
            g_output_buf_rows[i][j] = (JSAMPLE)(j * 13 + i);
        }
    }

    // Initialize other scalar temporaries to avoid undefined behavior
    tmp10 = tmp11 = tmp12 = tmp13 = tmp14 = 0;
    tmp20 = tmp21 = tmp22 = tmp23 = tmp24 = 0;
    z1 = z2 = z3 = z4 = 0;
    ctr = 0;
    outptr = NULL;
}