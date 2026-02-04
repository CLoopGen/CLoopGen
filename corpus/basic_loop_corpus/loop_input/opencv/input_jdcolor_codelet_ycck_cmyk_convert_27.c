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
JSAMPROW inptr3;
JDIMENSION col;
JDIMENSION num_cols;
JSAMPLE *range_limit;
int *Crrtab;
int *Cbbtab;
JLONG *Crgtab;
JLONG *Cbgtab;

void init_vars() {
    num_cols = 65536;  

    inptr0 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr1 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr2 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr3 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    outptr = (JSAMPROW)malloc(4 * num_cols * sizeof(JSAMPLE));

    range_limit = (JSAMPLE *)malloc(512 * sizeof(JSAMPLE));
    Crrtab = (int *)malloc(256 * sizeof(int));
    Cbbtab = (int *)malloc(256 * sizeof(int));
    Crgtab = (JLONG *)malloc(256 * sizeof(JLONG));
    Cbgtab = (JLONG *)malloc(256 * sizeof(JLONG));

    for (JDIMENSION i = 0; i < num_cols; i++) {
        inptr0[i] = (JSAMPLE)(i % 256);
        inptr1[i] = (JSAMPLE)((i * 7) % 256);
        inptr2[i] = (JSAMPLE)((i * 13) % 256);
        inptr3[i] = (JSAMPLE)((i * 17) % 256);
    }

    for (int i = 0; i < 256; i++) {
        Crrtab[i] = i * 2;
        Cbbtab[i] = i * 3;
        Crgtab[i] = (JLONG)(i * 4);
        Cbgtab[i] = (JLONG)(i * 5);
    }

    for (int i = 0; i < 512; i++) {
        range_limit[i] = (JSAMPLE)((i < 0) ? 0 : (i > 255) ? 255 : i);
    }

    col = 0;
}