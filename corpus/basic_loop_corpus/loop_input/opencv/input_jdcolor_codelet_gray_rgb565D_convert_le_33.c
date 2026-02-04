#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;
typedef long JLONG;

JSAMPROW inptr;
JSAMPROW outptr;
JDIMENSION col;
JSAMPLE *range_limit;
JDIMENSION num_cols;
JLONG d0;
JLONG rgb;
unsigned int g;

static JSAMPLE *inbuf;
static JSAMPLE *outbuf;
static JSAMPLE *range_limit_buf;

void init_vars() {
    const size_t input_size = 134217728; // 128 MB input data
    const size_t output_size = input_size / 2 * 4; // Each two input samples produce 4-byte output
    const size_t range_limit_size = 512; // Common size for range_limit (covers [-256, 255] offset)

    inbuf = (JSAMPLE *)aligned_alloc(32, input_size);
    outbuf = (JSAMPLE *)aligned_alloc(32, output_size);
    range_limit_buf = (JSAMPLE *)aligned_alloc(32, range_limit_size);

    if (!inbuf || !outbuf || !range_limit_buf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < input_size; i++) {
        inbuf[i] = (JSAMPLE)(i & 255);
    }
    for (size_t i = 0; i < output_size; i++) {
        outbuf[i] = 0;
    }
    for (size_t i = 0; i < range_limit_size; i++) {
        range_limit_buf[i] = (JSAMPLE)((i + 128) & 255);
    }

    inptr = inbuf;
    outptr = outbuf;
    range_limit = range_limit_buf;
    num_cols = (JDIMENSION)(input_size);
    d0 = 0x12345678L;
    rgb = 0;
    g = 0;
    col = 0;
}