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
    const size_t input_size = 64 * 1024 * 1024; // ~64MB of input data for sufficient runtime
    const size_t row_size = input_size;
    const size_t ctab_size = 3 * (256 + 1);

    inptr = (JSAMPROW)aligned_alloc(32, row_size);
    outptr = (JSAMPROW)aligned_alloc(32, row_size);
    ctab = (JLONG*)aligned_alloc(32, ctab_size * sizeof(JLONG));

    if (!inptr || !outptr || !ctab) {
        exit(1);
    }

    for (size_t i = 0; i < row_size; i++) {
        inptr[i] = (JSAMPLE)(i % 256);
    }

    for (size_t i = 0; i < ctab_size; i++) {
        ctab[i] = (JLONG)(i * 1000);
    }

    num_cols = (row_size / 4);
}