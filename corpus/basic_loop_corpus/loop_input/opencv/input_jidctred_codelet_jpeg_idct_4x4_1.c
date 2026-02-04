#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long JLONG;

// Define external variables
JSAMPARRAY output_buf;
JDIMENSION output_col;
JLONG tmp0;
JLONG tmp2;
JLONG tmp10;
JLONG tmp12;
JLONG z1;
JLONG z2;
JLONG z3;
JLONG z4;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

// Data arrays
static JSAMPLE *output_data;
static int *wsptr_data;
static JSAMPLE *range_limit_data;

void init_vars() {
    // Allocate range_limit: covers index (255*4+3) = 1023, so need at least 1024 entries
    range_limit_data = (JSAMPLE *)calloc(1024, sizeof(JSAMPLE));
    for (int i = 0; i < 1024; i++) {
        range_limit_data[i] = (JSAMPLE)((i & 255) % 256);
    }
    range_limit = range_limit_data;

    // We are running loop 4 times, each time using 8 ints from wsptr
    // So we need at least 4*8 = 32 int values
    wsptr_data = (int *)malloc(32 * sizeof(int));
    for (int i = 0; i < 32; i++) {
        wsptr_data[i] = (i % 8 == 0) ? 256 : ((i + 1) % 3); // Ensure not all zero except first of each block
    }
    wsptr = wsptr_data;

    // Each JSAMPROW in output_buf points to a row of 4 samples
    // We need 4 rows (for ctr = 0..3)
    output_data = (JSAMPLE *)calloc(4 * 8, sizeof(JSAMPLE)); // Extra space per row
    output_buf = (JSAMPROW *)malloc(4 * sizeof(JSAMPROW));
    for (int i = 0; i < 4; i++) {
        output_buf[i] = &output_data[i * 8];
    }

    // Set output_col to 0 to start writing at beginning of each row
    output_col = 0;

    // Initialize temp variables to zero (they are overwritten in loop anyway)
    tmp0 = tmp2 = tmp10 = tmp12 = z1 = z2 = z3 = z4 = 0;
    outptr = NULL;
    ctr = 0;
}