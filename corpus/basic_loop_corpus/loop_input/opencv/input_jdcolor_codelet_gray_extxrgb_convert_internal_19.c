#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

JSAMPROW inptr;
JSAMPROW outptr;
JDIMENSION col;
JDIMENSION num_cols;

static JSAMPLE *inbuf;
static JSAMPLE *outbuf;
static size_t total_input_size;
static size_t total_output_size;

void init_vars() {
    total_input_size = 64 * 1024 * 1024; // 64 MB input
    total_output_size = total_input_size * 4; // Each input produces 4 outputs

    inbuf = (JSAMPLE*)aligned_alloc(32, total_input_size);
    outbuf = (JSAMPLE*)aligned_alloc(32, total_output_size);

    if (!inbuf || !outbuf) {
        exit(1);
    }

    for (size_t i = 0; i < total_input_size; i++) {
        inbuf[i] = (JSAMPLE)(i & 0xFF);
    }

    for (size_t i = 0; i < total_output_size; i++) {
        outbuf[i] = 0;
    }

    inptr = inbuf;
    outptr = outbuf;
    num_cols = (JDIMENSION)total_input_size;
    col = 0;
}