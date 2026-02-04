#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

JSAMPLE *inptr_data;
JSAMPROW inptr;
JSAMPROW outptr;
JDIMENSION col;
JDIMENSION num_cols;
JSAMPLE *outptr_data;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB to ensure loop runtime ~0.01s
    inptr_data = (JSAMPLE*)aligned_alloc(32, data_size);
    outptr_data = (JSAMPLE*)aligned_alloc(32, data_size * 3);
    if (!inptr_data || !outptr_data) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        inptr_data[i] = (JSAMPLE)(i & 0xFF);
    }

    inptr = inptr_data;
    outptr = outptr_data;
    num_cols = (JDIMENSION)data_size;
}