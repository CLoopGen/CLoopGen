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
INT32 tmp10;
INT32 *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

#define WSPTR_SIZE (1024 * 1024 / sizeof(INT32))  // ~4MB of data to target 0.01s runtime
#define RANGE_LIMIT_SIZE ((128 << 2) * 2)

static JSAMPLE range_limit_data[RANGE_LIMIT_SIZE];
static INT32 wsptr_data[WSPTR_SIZE];
static JSAMPLE output_buf_data[4][1024];  // 4 rows, each up to 1024 samples

static JSAMPROW output_rows[4];

void init_vars() {
    // Initialize range_limit: maps shifted index into valid sample range
    for (int i = 0; i < RANGE_LIMIT_SIZE; i++) {
        range_limit_data[i] = (JSAMPLE)((i & 0xFF) % 256);
    }
    range_limit = range_limit_data;

    // Initialize wsptr with non-zero test values
    for (int i = 0; i < WSPTR_SIZE; i++) {
        wsptr_data[i] = (INT32)(i * 7919) ^ 0x55555555;  // arbitrary pattern
    }
    wsptr = wsptr_data;

    // Initialize output_buf rows
    for (int i = 0; i < 4; i++) {
        output_rows[i] = output_buf_data[i];
    }
    output_buf = output_rows;

    // Set output column within safe bounds (leave room for outptr[1])
    output_col = 512;  // well within 1024, ensures outptr[1] is valid
}