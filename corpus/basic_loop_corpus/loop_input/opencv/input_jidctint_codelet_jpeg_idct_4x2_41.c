#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long INT32;

// Define external variables
JSAMPARRAY output_buf;
JDIMENSION output_col;
INT32 tmp0;
INT32 tmp2;
INT32 tmp10;
INT32 tmp12;
INT32 z1;
INT32 z2;
INT32 z3;
INT32 *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01s runtime

static JSAMPLE *output_buffer_storage;
static INT32 *wsptr_storage;
static JSAMPLE *range_limit_storage;

void init_vars() {
    // Allocate large buffers to ensure sufficient workload
    output_buffer_storage = (JSAMPLE*)calloc(DATA_SIZE, sizeof(JSAMPLE));
    wsptr_storage = (INT32*)calloc(DATA_SIZE, sizeof(INT32));
    range_limit_storage = (JSAMPLE*)calloc(512, sizeof(JSAMPLE));

    if (!output_buffer_storage || !wsptr_storage || !range_limit_storage) {
        exit(1);
    }

    // Initialize range_limit to valid values (maps 0..511 to 0..255)
    for (int i = 0; i < 512; i++) {
        range_limit_storage[i] = (JSAMPLE)((i & 255));
    }

    // Initialize wsptr data with non-zero test pattern
    for (int i = 0; i < DATA_SIZE / sizeof(INT32); i++) {
        wsptr_storage[i] = (INT32)(i * i - (i + 1) * 3);
    }

    // Setup output_buf as array of row pointers
    output_buf = (JSAMPROW*)malloc(2 * sizeof(JSAMPROW));
    output_buf[0] = output_buffer_storage;
    output_buf[1] = output_buffer_storage + 1024;

    // Set column offset within safe bounds
    output_col = 0;

    // Initialize wsptr to start of workspace
    wsptr = wsptr_storage;

    // Initialize range_limit lookup table
    range_limit = range_limit_storage;

    // Zero out temporaries (will be overwritten in loop anyway)
    tmp0 = tmp2 = tmp10 = tmp12 = z1 = z2 = z3 = 0;
    outptr = NULL;
    ctr = 0;
}