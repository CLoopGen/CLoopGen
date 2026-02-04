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
    num_cols = data_size;

    inbuf = (JSAMPLE *)calloc(data_size * 3, sizeof(JSAMPLE));
    outbuf0 = (JSAMPLE *)calloc(data_size, sizeof(JSAMPLE));
    outbuf1 = (JSAMPLE *)calloc(data_size, sizeof(JSAMPLE));
    outbuf2 = (JSAMPLE *)calloc(data_size, sizeof(JSAMPLE));

    if (!inbuf || !outbuf0 || !outbuf1 || !outbuf2) {
        exit(1);
    }

    for (size_t i = 0; i < data_size * 3; i++) {
        inbuf[i] = (JSAMPLE)(i % 256);
    }

    inptr = inbuf;
    outptr0 = outbuf0;
    outptr1 = outbuf1;
    outptr2 = outbuf2;
}