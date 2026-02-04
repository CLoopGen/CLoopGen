#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long INT32;

// Data size: ~8MB of output buffer, ensures loop runs around 0.01s
#define DATA_SIZE (1 << 23)  // 8 * 1048576 = 8,388,608 bytes

static JSAMPLE* output_buf_data;
static float* wsptr_data;
static JSAMPLE* range_limit_data;

JSAMPARRAY output_buf;
JDIMENSION output_col;
float tmp0;
float tmp1;
float tmp2;
float tmp3;
float tmp4;
float tmp5;
float tmp6;
float tmp7;
float tmp10;
float tmp11;
float tmp12;
float tmp13;
float z5;
float z10;
float z11;
float z12;
float z13;
float *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

void init_vars() {
    // Allocate output buffer: 8 rows, each row has DATA_SIZE / 8 / 8 elements
    const int row_size = DATA_SIZE / 8 / 8;
    output_buf_data = (JSAMPLE*)calloc(8 * row_size, sizeof(JSAMPLE));
    output_buf = (JSAMPARRAY)calloc(8, sizeof(JSAMPROW));
    for (int i = 0; i < 8; i++) {
        output_buf[i] = output_buf_data + i * row_size;
    }

    // Initialize output column within bounds
    output_col = 0;

    // Allocate and initialize wsptr data: at least 8 * 8 floats
    wsptr_data = (float*)calloc(64, sizeof(float));
    wsptr = wsptr_data;

    // Simulated DCT coefficients for test
    for (int i = 0; i < 64; i++) {
        wsptr_data[i] = (float)((i % 7) - 3.0);
    }

    // Allocate and initialize range_limit: maps [-256, 511] to valid byte range
    range_limit_data = (JSAMPLE*)calloc(256 * 4 + 4, sizeof(JSAMPLE));
    range_limit = range_limit_data + 256; // Centered at 256 offset
    for (int i = -256; i < 512; i++) {
        range_limit[i] = (JSAMPLE)(i < 0 ? 0 : (i > 255 ? 255 : i));
    }
}