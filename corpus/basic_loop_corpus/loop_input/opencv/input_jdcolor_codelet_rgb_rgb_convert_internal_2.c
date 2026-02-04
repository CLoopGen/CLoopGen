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
    const size_t data_size = 64 * 1024 * 1024; // ~64MB per buffer to ensure sufficient workload

    inptr0 = (JSAMPROW)aligned_alloc(32, data_size);
    inptr1 = (JSAMPROW)aligned_alloc(32, data_size);
    inptr2 = (JSAMPROW)aligned_alloc(32, data_size);
    outptr = (JSAMPROW)aligned_alloc(32, 3 * data_size);

    if (!inptr0 || !inptr1 || !inptr2 || !outptr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    num_cols = data_size;

    for (size_t i = 0; i < data_size; i++) {
        inptr0[i] = (JSAMPLE)(i & 0xFF);
        inptr1[i] = (JSAMPLE)((i + 31) & 0xFF);
        inptr2[i] = (JSAMPLE)((i + 63) & 0xFF);
    }
}