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
    const size_t ctab_size = 3 * (255 + 1);
    ctab = (JLONG *)calloc(ctab_size, sizeof(JLONG));
    if (!ctab) exit(1);

    for (size_t i = 0; i < ctab_size; i++) {
        ctab[i] = (JLONG)(i * 17) << 8;
    }

    num_cols = (1024 * 1024 * 4) / 3;
    size_t in_size = num_cols * 4;
    size_t out_size = num_cols;

    inptr = (JSAMPROW)malloc(in_size * sizeof(JSAMPLE));
    outptr = (JSAMPROW)malloc(out_size * sizeof(JSAMPLE));
    if (!inptr || !outptr) exit(1);

    for (size_t i = 0; i < in_size; i++) {
        inptr[i] = (JSAMPLE)(i % 256);
    }
}