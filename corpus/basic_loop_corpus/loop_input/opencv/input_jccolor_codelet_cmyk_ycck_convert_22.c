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
JSAMPROW outptr3;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    const int DATA_SIZE = 64 * 1024 * 1024; // ~64MB to ensure loop runtime around 0.01s
    const int PADDED_SIZE = 256 + 1;
    const int CTAB_SIZE = 8 * PADDED_SIZE;

    ctab = (JLONG *)aligned_alloc(32, CTAB_SIZE * sizeof(JLONG));
    inptr = (JSAMPROW)aligned_alloc(32, DATA_SIZE);
    outptr0 = (JSAMPROW)aligned_alloc(32, DATA_SIZE / 4);
    outptr1 = (JSAMPROW)aligned_alloc(32, DATA_SIZE / 4);
    outptr2 = (JSAMPROW)aligned_alloc(32, DATA_SIZE / 4);
    outptr3 = (JSAMPROW)aligned_alloc(32, DATA_SIZE / 4);

    for (int i = 0; i < CTAB_SIZE; i++) {
        ctab[i] = (JLONG)(i * 17 % 65536) << 8;
    }

    for (int i = 0; i < DATA_SIZE; i++) {
        inptr[i] = (JSAMPLE)(i % 256);
    }

    num_cols = DATA_SIZE / 4;
}