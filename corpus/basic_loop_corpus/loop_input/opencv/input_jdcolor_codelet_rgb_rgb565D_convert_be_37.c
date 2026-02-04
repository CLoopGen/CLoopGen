#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;
typedef long JLONG;

JSAMPROW outptr;
JSAMPROW inptr0;
JSAMPROW inptr1;
JSAMPROW inptr2;
JDIMENSION col;
JSAMPLE *range_limit;
JDIMENSION num_cols;
JLONG d0;
JLONG rgb;
unsigned int r;
unsigned int g;
unsigned int b;

#define IN_SIZE (64 << 20)  // 64 MB input per channel
#define OUT_SIZE (IN_SIZE / 2 * 4)  // Two pixels per iteration, 4 bytes each

static JSAMPLE *in_buffer0;
static JSAMPLE *in_buffer1;
static JSAMPLE *in_buffer2;
static JSAMPLE *out_buffer;
static JSAMPLE *range_limit_buffer;

void init_vars() {
    in_buffer0 = aligned_alloc(32, IN_SIZE);
    in_buffer1 = aligned_alloc(32, IN_SIZE);
    in_buffer2 = aligned_alloc(32, IN_SIZE);
    out_buffer = aligned_alloc(32, OUT_SIZE);
    range_limit_buffer = malloc(512 * sizeof(JSAMPLE));

    for (size_t i = 0; i < IN_SIZE; i++) {
        in_buffer0[i] = (JSAMPLE)(i & 255);
        in_buffer1[i] = (JSAMPLE)((i >> 8) & 255);
        in_buffer2[i] = (JSAMPLE)((i >> 16) & 255);
    }

    for (int i = 0; i < 512; i++) {
        range_limit_buffer[i] = (JSAMPLE)((i < 256) ? ((i < 0) ? 0 : i) : 255);
    }

    inptr0 = in_buffer0;
    inptr1 = in_buffer1;
    inptr2 = in_buffer2;
    outptr = out_buffer;
    range_limit = range_limit_buffer;
    num_cols = IN_SIZE;
    d0 = 0x12345678;
    col = 0;
    rgb = 0;
    r = 0;
    g = 0;
    b = 0;
}