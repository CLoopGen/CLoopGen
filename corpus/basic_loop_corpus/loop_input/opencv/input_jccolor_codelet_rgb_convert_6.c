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

#define DATA_SIZE (64 * 1024 * 1024)

static JSAMPLE *inbuf;
static JSAMPLE *outbuf0;
static JSAMPLE *outbuf1;
static JSAMPLE *outbuf2;

void init_vars() {
    num_cols = DATA_SIZE;

    inbuf = (JSAMPLE*)aligned_alloc(32, 3 * num_cols * sizeof(JSAMPLE));
    outbuf0 = (JSAMPLE*)aligned_alloc(32, num_cols * sizeof(JSAMPLE));
    outbuf1 = (JSAMPLE*)aligned_alloc(32, num_cols * sizeof(JSAMPLE));
    outbuf2 = (JSAMPLE*)aligned_alloc(32, num_cols * sizeof(JSAMPLE));

    if (!inbuf || !outbuf0 || !outbuf1 || !outbuf2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (JDIMENSION i = 0; i < 3 * num_cols; i++) {
        inbuf[i] = (JSAMPLE)(i & 0xFF);
    }

    inptr = inbuf;
    outptr0 = outbuf0;
    outptr1 = outbuf1;
    outptr2 = outbuf2;
}