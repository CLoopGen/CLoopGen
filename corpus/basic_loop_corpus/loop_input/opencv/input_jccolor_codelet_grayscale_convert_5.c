#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

JSAMPLE *inptr_base;
JSAMPROW inptr;
JSAMPROW outptr;
JDIMENSION count;
int instride;
JDIMENSION num_cols;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // 128 MB of input data
    inptr_base = (JSAMPLE*)aligned_alloc(32, data_size);
    outptr = (JSAMPLE*)aligned_alloc(32, data_size);

    if (!inptr_base || !outptr) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        inptr_base[i] = (JSAMPLE)(i & 0xFF);
    }

    instride = 1;
    num_cols = data_size;

    inptr = inptr_base;
    count = num_cols;
}