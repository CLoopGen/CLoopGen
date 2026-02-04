#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long JLONG;

static JSAMPLE *range_limit_data;
static JSAMPROW outptr_rows[14];
static JSAMPLE output_buf_data[14][32]; // Ensure sufficient column size
static int wsptr_data[14 * 8]; // 14 iterations, 8 ints per iteration

JSAMPARRAY output_buf;
JDIMENSION output_col;
JLONG tmp10;
JLONG tmp11;
JLONG tmp12;
JLONG tmp13;
JLONG tmp14;
JLONG tmp15;
JLONG tmp16;
JLONG tmp20;
JLONG tmp21;
JLONG tmp22;
JLONG tmp23;
JLONG tmp24;
JLONG tmp25;
JLONG tmp26;
JLONG z1;
JLONG z2;
JLONG z3;
JLONG z4;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

void init_vars() {
    // Allocate and initialize range_limit: maps 0..1023 to valid sample values
    range_limit_data = (JSAMPLE *)calloc(1024 + 256, sizeof(JSAMPLE));
    range_limit = range_limit_data + 256; // Centered around 0 index access with offset
    for (int i = -256; i < 768; i++) {
        if (i < 0)
            range_limit[i + 256] = 0;
        else if (i > 255)
            range_limit[i + 256] = 255;
        else
            range_limit[i + 256] = (JSAMPLE)i;
    }

    // Initialize output_buf to point to pre-allocated row buffers
    output_buf = outptr_rows;
    for (int i = 0; i < 14; i++) {
        output_buf[i] = output_buf_data[i];
    }

    // Set output column within safe bounds (less than width - max offset used)
    output_col = 0; // Max offset used is 13, so col=0 is safe for width >=14

    // Initialize wsptr to point into allocated workspace
    wsptr = wsptr_data;

    // Initialize all scalar temporaries to zero
    tmp10 = tmp11 = tmp12 = tmp13 = tmp14 = tmp15 = tmp16 = 0;
    tmp20 = tmp21 = tmp22 = tmp23 = tmp24 = tmp25 = tmp26 = 0;
    z1 = z2 = z3 = z4 = 0;
    ctr = 0;

    // Initialize wsptr data with non-zero test values to avoid degenerate computation
    for (int i = 0; i < 14 * 8; i++) {
        wsptr_data[i] = (i * 17 + 13) % 1024; // Pseudo-random pattern
    }
}