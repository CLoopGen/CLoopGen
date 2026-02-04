#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long JLONG;

JSAMPLE *range_limit;
JSAMPARRAY output_buf;
JDIMENSION output_col;
JLONG tmp0;
JLONG tmp1;
JLONG tmp2;
JLONG tmp3;
JLONG tmp10;
JLONG tmp11;
JLONG tmp12;
JLONG tmp13;
JLONG z1;
JLONG z2;
JLONG z3;
JLONG z4;
JLONG z5;
int *wsptr;
JSAMPROW outptr;
int ctr;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to ensure ~0.01s runtime

static JSAMPLE *output_data;
static int *wsdata;

void init_vars() {
    // Allocate range_limit: map [0, 1023] -> valid sample values (clamp to 0-255)
    range_limit = (JSAMPLE *)malloc(1024 * sizeof(JSAMPLE));
    for (int i = 0; i < 1024; i++) {
        range_limit[i] = (JSAMPLE)((i & 255));
    }

    // Allocate output buffer: 8 rows of at least 8 samples each, but we make many blocks
    output_data = (JSAMPLE *)calloc(DATA_SIZE, sizeof(JSAMPLE));
    output_buf = (JSAMPROW *)malloc(8 * sizeof(JSAMPROW));
    for (int i = 0; i < 8; i++) {
        output_buf[i] = &output_data[i * (DATA_SIZE / 8)];
    }
    output_col = 0; // Start at beginning of column

    // Allocate and initialize wsptr data: multiple blocks of 8 integers
    wsdata = (int *)malloc(DATA_SIZE * sizeof(int));
    for (int i = 0; i < DATA_SIZE; i++) {
        // Mix zero and non-zero blocks to trigger both branches
        if ((i / 8) % 2 == 0) {
            wsdata[i] = 0;
        } else {
            wsdata[i] = (i * 1234567) % 1000;
        }
    }
    wsptr = wsdata;

    // Initialize loop-carried temporaries to zero
    tmp0 = tmp1 = tmp2 = tmp3 = 0;
    tmp10 = tmp11 = tmp12 = tmp13 = 0;
    z1 = z2 = z3 = z4 = z5 = 0;
    ctr = 0;
    outptr = output_buf[0];
}