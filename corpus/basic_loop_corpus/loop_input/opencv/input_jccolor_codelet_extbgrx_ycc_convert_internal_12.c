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
    const size_t input_size = 64 * 1024 * 1024; // ~64MB of RGBA data
    const size_t ctab_size = 8 * (256 + 1);
    const size_t output_size = input_size / 4; // one pixel per 4-byte input

    inptr = (JSAMPROW)aligned_alloc(32, input_size);
    outptr0 = (JSAMPROW)aligned_alloc(32, output_size);
    outptr1 = (JSAMPROW)aligned_alloc(32, output_size);
    outptr2 = (JSAMPROW)aligned_alloc(32, output_size);
    ctab = (JLONG *)aligned_alloc(32, ctab_size * sizeof(JLONG));

    for (size_t i = 0; i < input_size; i++) {
        inptr[i] = rand() % 256;
    }
    for (size_t i = 0; i < ctab_size; i++) {
        ctab[i] = rand() % 65536;
    }

    num_cols = output_size;
    col = 0;
}