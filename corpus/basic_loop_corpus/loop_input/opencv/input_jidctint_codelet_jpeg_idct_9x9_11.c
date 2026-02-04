#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long JLONG;

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
JLONG tmp14;
JLONG z1;
JLONG z2;
JLONG z3;
JLONG z4;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

void init_vars() {
    const int data_size = 1 << 20; // ~1MB of input data
    const int num_rows = 9;
    const int row_width = 16; // Ensure enough space for outptr + 8

    // Allocate range_limit: maps 0-1023 to valid sample values (clamp to 0-255)
    range_limit = (JSAMPLE *)malloc(1024 * sizeof(JSAMPLE));
    for (int i = 0; i < 1024; i++) {
        int val = (i - 256) & 1023;
        if (val < 0) val = 0;
        if (val > 255) val = 255;
        range_limit[i] = (JSAMPLE)val;
    }

    // Allocate output_buf as array of 9 row pointers
    output_buf = (JSAMPARRAY)malloc(num_rows * sizeof(JSAMPROW));
    for (int i = 0; i < num_rows; i++) {
        output_buf[i] = (JSAMPROW)malloc(row_width * sizeof(JSAMPLE));
        for (int j = 0; j < row_width; j++) {
            output_buf[i][j] = (JSAMPLE)(j ^ (i * 17));
        }
    }

    // Initialize output_col to a safe offset within row_width
    output_col = 0; // Ensures output_buf[ctr] + output_col + 8 is in bounds

    // Allocate wsptr to point to a block of 9 * 8 integers (each loop uses 8, 9 iterations)
    wsptr = (int *)malloc(data_size * sizeof(int));
    for (int i = 0; i < data_size; i++) {
        wsptr[i] = (int)((i * 1234567LL) % 16384);
    }
}