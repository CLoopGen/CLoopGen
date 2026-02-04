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
    const size_t data_size = 64 * 1024 * 1024; // Approximate input size for ~0.01 sec runtime
    num_cols = data_size / 3; // Divide by 3 input channels

    inptr0 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr1 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr2 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    outptr = (JSAMPROW)malloc(num_cols * 4 * sizeof(JSAMPLE));

    range_limit = (JSAMPLE *)malloc(512 * sizeof(JSAMPLE));
    for (int i = 0; i < 512; i++) {
        range_limit[i] = (JSAMPLE)((i < 0) ? 0 : ((i > 255) ? 255 : i));
    }

    Crrtab = (int *)malloc(256 * sizeof(int));
    Cbbtab = (int *)malloc(256 * sizeof(int));
    Crgtab = (JLONG *)malloc(256 * sizeof(JLONG));
    Cbgtab = (JLONG *)malloc(256 * sizeof(JLONG));

    for (int i = 0; i < 256; i++) {
        Crrtab[i] = 100 + i; 
        Cbbtab[i] = 150 + i;
        Crgtab[i] = (JLONG)(1 << 15) + i * 10;
        Cbgtab[i] = (JLONG)(1 << 15) + i * 12;
    }

    for (JDIMENSION i = 0; i < num_cols; i++) {
        inptr0[i] = (JSAMPLE)(128 + (i % 20));
        inptr1[i] = (JSAMPLE)(128 + (i % 30));
        inptr2[i] = (JSAMPLE)(128 + (i % 40));
    }

    col = 0;
}