#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

int r;
int g;
int b;
JSAMPROW outptr;
JSAMPROW inptr0;
JSAMPROW inptr1;
JSAMPROW inptr2;
JDIMENSION col;
JDIMENSION num_cols;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01 sec runtime

static JSAMPLE *inbuf0;
static JSAMPLE *inbuf1;
static JSAMPLE *inbuf2;
static JSAMPLE *outbuf;

void init_vars() {
    // Allocate input and output buffers
    inbuf0 = (JSAMPLE *)aligned_alloc(32, DATA_SIZE);
    inbuf1 = (JSAMPLE *)aligned_alloc(32, DATA_SIZE);
    inbuf2 = (JSAMPLE *)aligned_alloc(32, DATA_SIZE);
    outbuf = (JSAMPLE *)aligned_alloc(32, DATA_SIZE * 3);

    // Initialize input pointers
    inptr0 = inbuf0;
    inptr1 = inbuf1;
    inptr2 = inbuf2;
    outptr = outbuf;

    // Set number of columns to process
    num_cols = DATA_SIZE;

    // Initialize input data with non-zero values for realistic processing
    for (JDIMENSION i = 0; i < num_cols; i++) {
        inbuf0[i] = (JSAMPLE)(i & 255);
        inbuf1[i] = (JSAMPLE)((i >> 4) & 255);
        inbuf2[i] = (JSAMPLE)((i >> 8) & 255);
    }

    col = 0;
}