#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

JSAMPROW inptr;
JSAMPROW outptr0;
JSAMPROW outptr1;
JSAMPROW outptr2;
JDIMENSION col;
JDIMENSION num_cols;

static JSAMPLE *inbuf;
static JSAMPLE *outbuf0;
static JSAMPLE *outbuf1;
static JSAMPLE *outbuf2;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; 
    num_cols = data_size / 3;

    inbuf = (JSAMPLE *)aligned_alloc(32, data_size);
    outbuf0 = (JSAMPLE *)aligned_alloc(32, num_cols);
    outbuf1 = (JSAMPLE *)aligned_alloc(32, num_cols);
    outbuf2 = (JSAMPLE *)aligned_alloc(32, num_cols);

    for (size_t i = 0; i < data_size; i++) {
        inbuf[i] = (JSAMPLE)(i & 0xFF);
    }

    outptr0 = outbuf0;
    outptr1 = outbuf1;
    outptr2 = outbuf2;
    inptr = inbuf;
}

__attribute__((destructor))
static void cleanup() {
    free(inbuf);
    free(outbuf0);
    free(outbuf1);
    free(outbuf2);
}