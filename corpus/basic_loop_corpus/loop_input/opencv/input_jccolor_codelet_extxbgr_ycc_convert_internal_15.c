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
JSAMPROW outptr0;
JSAMPROW outptr1;
JSAMPROW outptr2;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    const size_t input_size = 64 * 1024 * 1024; // ~64MB of input data to target 0.01 sec runtime
    num_cols = input_size / 4;

    inptr = (JSAMPROW)aligned_alloc(32, input_size);
    outptr0 = (JSAMPROW)aligned_alloc(32, num_cols);
    outptr1 = (JSAMPROW)aligned_alloc(32, num_cols);
    outptr2 = (JSAMPROW)aligned_alloc(32, num_cols);

    for (size_t i = 0; i < input_size; i++) {
        inptr[i] = (JSAMPLE)(i % 256);
    }

    ctab = (JLONG *)aligned_alloc(32, 8 * (256 + 1) * sizeof(JLONG));
    for (int i = 0; i < 8 * (256 + 1); i++) {
        ctab[i] = (JLONG)(i * 1000);
    }

    col = 0;
}