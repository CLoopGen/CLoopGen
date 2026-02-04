#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

JSAMPLE *inptr;
JSAMPROW outptr0;
JSAMPROW outptr1;
JSAMPROW outptr2;
JDIMENSION col;
JDIMENSION num_cols;

static JSAMPLE *inbuf;
static JSAMPROW outbuf0;
static JSAMPROW outbuf1;
static JSAMPROW outbuf2;

void init_vars() {
    num_cols = 64 * 1024; // 64K columns -> ~256KB input, scales well for ~0.01s runtime

    size_t in_size = (size_t)num_cols * 4 * sizeof(JSAMPLE);
    size_t out_size = (size_t)num_cols * sizeof(JSAMPLE);

    inbuf = (JSAMPLE*)aligned_alloc(32, in_size);
    outbuf0 = (JSAMPROW)aligned_alloc(32, out_size);
    outbuf1 = (JSAMPROW)aligned_alloc(32, out_size);
    outbuf2 = (JSAMPROW)aligned_alloc(32, out_size);

    if (!inbuf || !outbuf0 || !outbuf1 || !outbuf2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < in_size; i++) {
        inbuf[i] = (JSAMPLE)(i & 0xFF);
    }
    for (size_t i = 0; i < out_size; i++) {
        outbuf0[i] = 0;
        outbuf1[i] = 0;
        outbuf2[i] = 0;
    }

    inptr = inbuf;
    outptr0 = outbuf0;
    outptr1 = outbuf1;
    outptr2 = outbuf2;
}