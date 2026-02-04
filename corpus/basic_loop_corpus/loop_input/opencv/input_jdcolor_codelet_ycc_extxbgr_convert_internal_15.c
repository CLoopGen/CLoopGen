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
    num_cols = 64 * 1024;  // Adjust to achieve ~0.01 sec runtime

    inptr0 = (JSAMPROW)aligned_alloc(32, num_cols * sizeof(JSAMPLE));
    inptr1 = (JSAMPROW)aligned_alloc(32, num_cols * sizeof(JSAMPLE));
    inptr2 = (JSAMPROW)aligned_alloc(32, num_cols * sizeof(JSAMPLE));
    outptr = (JSAMPROW)aligned_alloc(32, num_cols * 4 * sizeof(JSAMPLE));

    range_limit = (JSAMPLE*)aligned_alloc(32, 65536 * sizeof(JSAMPLE));
    Crrtab = (int*)aligned_alloc(32, 65536 * sizeof(int));
    Cbbtab = (int*)aligned_alloc(32, 65536 * sizeof(int));
    Crgtab = (JLONG*)aligned_alloc(32, 65536 * sizeof(JLONG));
    Cbgtab = (JLONG*)aligned_alloc(32, 65536 * sizeof(JLONG));

    for (size_t i = 0; i < num_cols; i++) {
        inptr0[i] = rand() % 256;
        inptr1[i] = rand() % 256;
        inptr2[i] = rand() % 256;
    }

    for (size_t i = 0; i < 65536; i++) {
        range_limit[i] = (JSAMPLE)(i & 255);
        Crrtab[i] = (i % 256) - 128;
        Cbbtab[i] = (i % 256) - 128;
        Crgtab[i] = (JLONG)(rand() % 512) - 256;
        Cbgtab[i] = (JLONG)(rand() % 512) - 256;
    }
}