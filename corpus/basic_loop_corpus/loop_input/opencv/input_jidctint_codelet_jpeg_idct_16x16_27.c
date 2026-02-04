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
extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 tmp25;
extern INT32 tmp26;
extern INT32 tmp27;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Definitions of external variables
JSAMPARRAY output_buf;
JDIMENSION output_col = 0;
INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
INT32 tmp3;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
INT32 tmp20;
INT32 tmp21;
INT32 tmp22;
INT32 tmp23;
INT32 tmp24;
INT32 tmp25;
INT32 tmp26;
INT32 tmp27;
INT32 z1;
INT32 z2;
INT32 z3;
INT32 z4;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

// Internal storage
static int *wsptr_storage;
static JSAMPLE *range_limit_storage;
static JSAMPLE **output_buf_storage;
static JSAMPLE *output_pixels;

void init_vars() {
    // Allocate range_limit: covers index range [0, (128<<2)*2-1] => [0, 1023]
    range_limit_storage = (JSAMPLE *)calloc(1024, sizeof(JSAMPLE));
    for (int i = 0; i < 1024; i++) {
        range_limit_storage[i] = (JSAMPLE)((i & 255));
    }
    range_limit = range_limit_storage;

    // Each iteration uses 8 ints from wsptr; loop runs 16 times -> need 128 ints
    wsptr_storage = (int *)malloc(128 * sizeof(int));
    for (int i = 0; i < 128; i++) {
        wsptr_storage[i] = (i % 2 == 0) ? (100 + i) : -(100 + i);
    }
    wsptr = wsptr_storage;

    // output_buf[ctr] points to a row; each row has at least output_col + 16 elements
    output_col = 0;
    output_buf_storage = (JSAMPLE **)malloc(16 * sizeof(JSAMPLE *));
    output_pixels = (JSAMPLE *)malloc(16 * 16 * sizeof(JSAMPLE));
    for (int i = 0; i < 16; i++) {
        output_buf_storage[i] = output_pixels + i * 16;
    }
    output_buf = output_buf_storage;

    // Initialize temporary variables to zero to ensure defined behavior
    tmp0 = tmp1 = tmp2 = tmp3 = 0;
    tmp10 = tmp11 = tmp12 = tmp13 = 0;
    tmp20 = tmp21 = tmp22 = tmp23 = tmp24 = tmp25 = tmp26 = tmp27 = 0;
    z1 = z2 = z3 = z4 = 0;
    outptr = NULL;
    ctr = 0;
}