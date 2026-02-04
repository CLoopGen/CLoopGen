#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

JSAMPROW inptr0;
JSAMPROW inptr1;
JSAMPROW inptr2;
JSAMPROW outptr;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    const size_t input_size = 64 * 1024 * 1024; // ~64MB total input data
    num_cols = input_size / 3; // Each input row has one-third of the data

    // Allocate input arrays
    inptr0 = (JSAMPROW)aligned_alloc(32, sizeof(JSAMPLE) * num_cols);
    inptr1 = (JSAMPROW)aligned_alloc(32, sizeof(JSAMPLE) * num_cols);
    inptr2 = (JSAMPROW)aligned_alloc(32, sizeof(JSAMPLE) * num_cols);

    // Allocate output array: 4 bytes per column
    size_t out_size = num_cols * 4;
    outptr = (JSAMPROW)aligned_alloc(32, out_size);

    // Initialize input data to non-zero values for realism
    for (JDIMENSION i = 0; i < num_cols; i++) {
        inptr0[i] = (JSAMPLE)(i & 0xFF);
        inptr1[i] = (JSAMPLE)((i + 33) & 0xFF);
        inptr2[i] = (JSAMPLE)((i + 66) & 0xFF);
    }

    col = 0; // Initialize loop counter
}