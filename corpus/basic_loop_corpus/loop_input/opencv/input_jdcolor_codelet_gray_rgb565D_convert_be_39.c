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

#define DATA_SIZE_MB 64
#define TOTAL_BYTES (DATA_SIZE_MB * 1024 * 1024)

static JSAMPLE in_buffer[TOTAL_BYTES];
static JSAMPLE out_buffer[TOTAL_BYTES];
static JSAMPLE range_limit_array[512]; // sufficient size to avoid bounds issues

void init_vars() {
    // Initialize scalar variables
    col = 0;
    d0 = 0x12345678L;
    rgb = 0;
    g = 0;
    num_cols = (TOTAL_BYTES / 2); // ensures we do num_cols >> 1 iterations, each consuming 2 input bytes

    // Initialize pointers to point into our static buffers
    inptr = in_buffer;
    outptr = out_buffer;
    range_limit = range_limit_array + 256; // center the range so that index (g + (d0 & 255)) is valid

    // Initialize input buffer with non-zero test data
    for (size_t i = 0; i < TOTAL_BYTES; ++i) {
        in_buffer[i] = (JSAMPLE)(i & 255);
    }

    // Initialize range_limit array: identity mapping with offset handling
    for (int i = -256; i < 256; ++i) {
        if (i < 0) {
            range_limit_array[i + 256] = 0;
        } else if (i > 255) {
            range_limit_array[i + 256] = 255;
        } else {
            range_limit_array[i + 256] = (JSAMPLE)i;
        }
    }
}