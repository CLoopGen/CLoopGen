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
    num_cols = 64 * 1024;  // ~192KB input, should run in ~0.01s on modern CPU

    inbuf = (JSAMPLE*)calloc(num_cols * 3, sizeof(JSAMPLE));
    outbuf0 = (JSAMPLE*)malloc(num_cols * sizeof(JSAMPLE));
    outbuf1 = (JSAMPLE*)malloc(num_cols * sizeof(JSAMPLE));
    outbuf2 = (JSAMPLE*)malloc(num_cols * sizeof(JSAMPLE));

    if (!inbuf || !outbuf0 || !outbuf1 || !outbuf2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (JDIMENSION i = 0; i < num_cols * 3; i++) {
        inbuf[i] = rand() & 255;
    }

    inptr = inbuf;
    outptr0 = outbuf0;
    outptr1 = outbuf1;
    outptr2 = outbuf2;
    col = 0;
}