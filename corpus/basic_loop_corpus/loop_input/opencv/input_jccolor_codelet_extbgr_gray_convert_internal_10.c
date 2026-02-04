#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long JLONG;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

int r;
int g;
int b;
JLONG *ctab;
JSAMPROW inptr;
JSAMPROW outptr;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    const size_t input_size = 64 * 1024 * 1024; // ~64MB of RGB data
    num_cols = input_size / 3;

    inptr = (JSAMPROW)aligned_alloc(32, input_size);
    outptr = (JSAMPROW)aligned_alloc(32, num_cols);

    ctab = (JLONG*)aligned_alloc(32, 3 * (256 + 1) * sizeof(JLONG));

    for (size_t i = 0; i < input_size; i++) {
        inptr[i] = (JSAMPLE)(i % 256);
    }

    for (int i = 0; i < 3 * (256 + 1); i++) {
        ctab[i] = (JLONG)(i * 12345L);
    }
}