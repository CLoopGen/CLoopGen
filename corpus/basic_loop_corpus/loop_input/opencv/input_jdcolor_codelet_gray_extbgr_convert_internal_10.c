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

void init_vars() {
    const size_t input_size = 64 * 1024 * 1024; // 64 MB input data
    const size_t output_size = input_size * 3;  // Each input element produces 3 output elements

    inptr = (JSAMPROW)aligned_alloc(32, input_size * sizeof(JSAMPLE));
    outptr = (JSAMPROW)aligned_alloc(32, output_size * sizeof(JSAMPLE));

    if (!inptr || !outptr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < input_size; i++) {
        inptr[i] = (JSAMPLE)(i & 0xFF);
    }

    num_cols = (JDIMENSION)input_size;
    col = 0;
}