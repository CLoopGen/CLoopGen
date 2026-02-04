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
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
INT32 tmp14;
INT32 z1;
INT32 z2;
INT32 z3;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

#define DATA_SIZE (1 << 20)  // ~1MB of data for appropriate timing

static JSAMPLE *output_buffer_pool = NULL;
static int *wsptr_data = NULL;
static JSAMPLE *range_limit_data = NULL;

void init_vars() {
    // Allocate range_limit: covers index range [0, (128<<2)*2 - 1] => [0, 1023]
    range_limit_data = calloc(1024, sizeof(JSAMPLE));
    for (int i = 0; i < 1024; ++i) {
        range_limit_data[i] = (JSAMPLE)((i & 255));
    }
    range_limit = range_limit_data;

    // Allocate output_buf: 10 rows, each row has at least output_col+5 elements
    output_col = 0;  // Ensure no offset overflow
    output_buffer_pool = calloc(10 * 16, sizeof(JSAMPLE));  // 10 rows, 16 cols min
    output_buf = malloc(10 * sizeof(JSAMPROW));
    for (int i = 0; i < 10; ++i) {
        output_buf[i] = &output_buffer_pool[i * 16];
    }

    // Allocate wsptr_data: loop runs 10 times, each time accesses 5 ints, so need 50 ints
    wsptr_data = malloc(50 * sizeof(int));
    for (int i = 0; i < 50; ++i) {
        wsptr_data[i] = (i + 1) * 32;  // Non-zero predictable values
    }
    wsptr = wsptr_data;

    // Initialize scalars
    tmp10 = 0;
    tmp11 = 0;
    tmp12 = 0;
    tmp13 = 0;
    tmp14 = 0;
    z1 = 0;
    z2 = 0;
    z3 = 0;
    outptr = NULL;
    ctr = 0;
}