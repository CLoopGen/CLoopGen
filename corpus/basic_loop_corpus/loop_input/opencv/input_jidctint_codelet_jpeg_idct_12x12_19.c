#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long INT32;

static JSAMPLE range_limit_data[1024];
JSAMPARRAY output_buf;
JDIMENSION output_col;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
INT32 tmp14;
INT32 tmp15;
INT32 tmp20;
INT32 tmp21;
INT32 tmp22;
INT32 tmp23;
INT32 tmp24;
INT32 tmp25;
INT32 z1;
INT32 z2;
INT32 z3;
INT32 z4;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

static int wsptr_data[96];  // 12 iterations * 8 elements per iteration

void init_vars() {
    // Allocate and initialize range_limit
    for (int i = 0; i < 1024; i++) {
        range_limit_data[i] = (JSAMPLE)((i & 511) > 255 ? 255 : (i & 511));
    }
    range_limit = range_limit_data;

    // Set output_col to a valid column offset
    output_col = 0;

    // Allocate output_buf: 12 rows, each row has at least 12 columns
    output_buf = malloc(12 * sizeof(JSAMPROW));
    for (int i = 0; i < 12; i++) {
        output_buf[i] = malloc(16 * sizeof(JSAMPLE));
        for (int j = 0; j < 16; j++) {
            output_buf[i][j] = 0;
        }
    }

    // Initialize wsptr_data with non-zero values to simulate transformed data
    for (int i = 0; i < 96; i++) {
        wsptr_data[i] = (i % 8) == 0 ? 1024 : ((i + 1) * 17) % 256 - 128;
    }
    wsptr = wsptr_data;

    // Initialize other scalar variables to zero
    tmp10 = 0;
    tmp11 = 0;
    tmp12 = 0;
    tmp13 = 0;
    tmp14 = 0;
    tmp15 = 0;
    tmp20 = 0;
    tmp21 = 0;
    tmp22 = 0;
    tmp23 = 0;
    tmp24 = 0;
    tmp25 = 0;
    z1 = 0;
    z2 = 0;
    z3 = 0;
    z4 = 0;
    ctr = 0;
    outptr = NULL;
}