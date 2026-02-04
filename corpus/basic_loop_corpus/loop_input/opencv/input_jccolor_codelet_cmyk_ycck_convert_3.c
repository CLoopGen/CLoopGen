#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long INT32;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

int r;
int g;
int b;
INT32 *ctab;
JSAMPROW inptr;
JSAMPROW outptr0;
JSAMPROW outptr1;
JSAMPROW outptr2;
JSAMPROW outptr3;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    const size_t input_size = 64 * 1024 * 1024; // ~64MB of input data for ~0.01 sec runtime estimate
    num_cols = input_size / 4;

    inptr = (JSAMPROW)aligned_alloc(32, input_size);
    outptr0 = (JSAMPROW)aligned_alloc(32, num_cols);
    outptr1 = (JSAMPROW)aligned_alloc(32, num_cols);
    outptr2 = (JSAMPROW)aligned_alloc(32, num_cols);
    outptr3 = (JSAMPROW)aligned_alloc(32, num_cols);

    ctab = (INT32*)aligned_alloc(32, (8 * (255 + 1)) * sizeof(INT32));

    for (size_t i = 0; i < input_size; i++) {
        inptr[i] = (JSAMPLE)(i % 256);
    }

    for (int i = 0; i < (8 * (255 + 1)); i++) {
        ctab[i] = (INT32)(i * 1000); 
    }

    r = 0;
    g = 0;
    b = 0;
    col = 0;
}