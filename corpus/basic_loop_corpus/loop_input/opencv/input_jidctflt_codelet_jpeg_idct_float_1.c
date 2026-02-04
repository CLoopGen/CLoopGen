#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;

// Define constants used in the loop
#define DATA_SIZE (16 * 1024 * 1024) // ~16MB to target ~0.01s runtime
#define ALIGNMENT 32

// Allocate aligned memory for critical arrays
static float *wsptr_base = NULL;
static JSAMPLE *range_limit_base = NULL;
static JSAMPLE **output_buf_rows = NULL;
static JSAMPLE *output_buf_data = NULL;

// Extern variables
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
    // Initialize scalars
    output_col = 0;
    ctr = 0;

    // Allocate wsptr: needs at least 8 * 8 = 64 floats (8 iterations × 8 stride)
    posix_memalign((void**)&wsptr_base, ALIGNMENT, DATA_SIZE);
    wsptr = wsptr_base;

    // Initialize wsptr data with non-zero values to simulate real input
    for (size_t i = 0; i < DATA_SIZE / sizeof(float); i++) {
        wsptr_base[i] = (float)(i % 251 - 125) * 0.5f; // Prime pattern to avoid zeros
    }

    // Allocate range_limit: needs at least 256*4+4 entries as per & (255*4+3)
    range_limit_base = (JSAMPLE*)malloc(256 * 4 + 4);
    for (int i = 0; i < 256 * 4 + 4; i++) {
        range_limit_base[i] = (JSAMPLE)((i >> 2) & 0xFF); // Map every 4 slots to same byte value
    }
    range_limit = range_limit_base;

    // Allocate output buffer: 8 rows, each with at least 8 columns (we use 16 for safety)
    output_buf_rows = (JSAMPROW*)malloc(8 * sizeof(JSAMPROW));
    output_buf_data = (JSAMPLE*)malloc(8 * 16 * sizeof(JSAMPLE));
    
    for (int i = 0; i < 8; i++) {
        output_buf_rows[i] = &output_buf_data[i * 16];
    }
    output_buf = output_buf_rows;
}