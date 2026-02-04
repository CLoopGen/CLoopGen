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
    const size_t input_size = 64 * 1024 * 1024; // ~64MB input data for ~0.01s runtime estimate
    num_cols = input_size;

    inptr = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    if (!inptr) exit(1);

    for (JDIMENSION i = 0; i < num_cols; ++i) {
        inptr[i] = (JSAMPLE)(i % 256);
    }

    size_t out_size = num_cols * 4 * sizeof(JSAMPLE);
    outptr = (JSAMPROW)malloc(out_size);
    if (!outptr) {
        free(inptr);
        exit(1);
    }
}