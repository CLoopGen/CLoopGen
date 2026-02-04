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
    const JDIMENSION data_size = 64 * 1024 * 1024; // ~64MB input for ~0.01 sec runtime estimate
    num_cols = data_size / 4; // each pixel takes 4 bytes in input

    ctab = (JLONG *)aligned_alloc(32, sizeof(JLONG) * (8 * (255 + 1)));
    if (!ctab) exit(1);
    for (int i = 0; i < 8 * (255 + 1); i++) {
        ctab[i] = (JLONG)(i * 1000); // arbitrary initialization
    }

    inptr = (JSAMPROW)aligned_alloc(32, data_size);
    if (!inptr) exit(1);
    for (size_t i = 0; i < data_size; i++) {
        inptr[i] = (JSAMPLE)(i % 256);
    }

    outptr0 = (JSAMPROW)aligned_alloc(32, num_cols * sizeof(JSAMPLE));
    outptr1 = (JSAMPROW)aligned_alloc(32, num_cols * sizeof(JSAMPLE));
    outptr2 = (JSAMPROW)aligned_alloc(32, num_cols * sizeof(JSAMPLE));
    if (!outptr0 || !outptr1 || !outptr2) exit(1);

    col = 0;
}