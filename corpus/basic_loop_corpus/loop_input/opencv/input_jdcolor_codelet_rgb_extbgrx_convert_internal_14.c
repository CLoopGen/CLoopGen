#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

JSAMPLE *inptr0;
JSAMPLE *inptr1;
JSAMPLE *inptr2;
JSAMPLE *outptr;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    const size_t input_size = 64 * 1024 * 1024; // ~64MB per buffer to target ~0.01s runtime
    num_cols = input_size;

    inptr0 = (JSAMPLE*)aligned_alloc(32, input_size * sizeof(JSAMPLE));
    inptr1 = (JSAMPLE*)aligned_alloc(32, input_size * sizeof(JSAMPLE));
    inptr2 = (JSAMPLE*)aligned_alloc(32, input_size * sizeof(JSAMPLE));
    outptr = (JSAMPLE*)aligned_alloc(32, input_size * 4 * sizeof(JSAMPLE));

    for (size_t i = 0; i < input_size; i++) {
        inptr0[i] = (JSAMPLE)(i & 0xFF);
        inptr1[i] = (JSAMPLE)((i + 33) & 0xFF);
        inptr2[i] = (JSAMPLE)((i + 65) & 0xFF);
    }
}