#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;
typedef long JLONG;

int y;
int cb;
int cr;
JSAMPROW outptr;
JSAMPROW inptr0;
JSAMPROW inptr1;
JSAMPROW inptr2;
JDIMENSION col;
JDIMENSION num_cols;
JSAMPLE *range_limit;
int *Crrtab;
int *Cbbtab;
JLONG *Crgtab;
JLONG *Cbgtab;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of input data for sufficient runtime
    num_cols = data_size;

    inptr0 = malloc(num_cols * sizeof(JSAMPLE));
    inptr1 = malloc(num_cols * sizeof(JSAMPLE));
    inptr2 = malloc(num_cols * sizeof(JSAMPLE));
    outptr = malloc(4 * num_cols * sizeof(JSAMPLE));

    range_limit = malloc(512 * sizeof(JSAMPLE));
    for (int i = 0; i < 512; i++) {
        range_limit[i] = (JSAMPLE)((i < 0) ? 0 : (i > 255) ? 255 : i);
    }

    Crrtab = malloc(256 * sizeof(int));
    Cbbtab = malloc(256 * sizeof(int));
    Crgtab = malloc(256 * sizeof(JLONG));
    Cbgtab = malloc(256 * sizeof(JLONG));

    for (int i = 0; i < 256; i++) {
        Crrtab[i] = i * 2;
        Cbbtab[i] = i * 3;
        Crgtab[i] = (JLONG)(i * 1.5);
        Cbgtab[i] = (JLONG)(i * 2.5);
    }

    for (JDIMENSION i = 0; i < num_cols; i++) {
        inptr0[i] = (JSAMPLE)(i % 256);
        inptr1[i] = (JSAMPLE)((i * 7) % 256);
        inptr2[i] = (JSAMPLE)((i * 11) % 256);
    }
}