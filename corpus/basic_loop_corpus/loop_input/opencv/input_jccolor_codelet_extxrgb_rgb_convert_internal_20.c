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

#define DATA_SIZE (64 * 1024 * 1024)  // 64 MB of input data

static JSAMPLE *inbuf;
static JSAMPLE *outbuf0;
static JSAMPLE *outbuf1;
static JSAMPLE *outbuf2;

void init_vars() {
    inbuf = (JSAMPLE *)calloc(DATA_SIZE, sizeof(JSAMPLE));
    outbuf0 = (JSAMPLE *)calloc(DATA_SIZE, sizeof(JSAMPLE));
    outbuf1 = (JSAMPLE *)calloc(DATA_SIZE, sizeof(JSAMPLE));
    outbuf2 = (JSAMPLE *)calloc(DATA_SIZE, sizeof(JSAMPLE));

    if (!inbuf || !outbuf0 || !outbuf1 || !outbuf2) {
        exit(1);
    }

    inptr = inbuf;
    outptr0 = outbuf0;
    outptr1 = outbuf1;
    outptr2 = outbuf2;

    num_cols = DATA_SIZE / 4;  // Ensure we don't exceed bounds: each iteration reads 4 bytes
}