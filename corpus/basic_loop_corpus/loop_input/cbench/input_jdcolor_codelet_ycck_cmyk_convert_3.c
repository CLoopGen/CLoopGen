#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;
typedef long INT32;

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
INT32 *Crgtab;
INT32 *Cbgtab;

#define DATA_SIZE (64 * 1024 * 1024)

void init_vars() {
    num_cols = DATA_SIZE;

    inptr0 = (JSAMPROW)malloc(DATA_SIZE * sizeof(JSAMPLE));
    inptr1 = (JSAMPROW)malloc(DATA_SIZE * sizeof(JSAMPLE));
    inptr2 = (JSAMPROW)malloc(DATA_SIZE * sizeof(JSAMPLE));
    inptr3 = (JSAMPROW)malloc(DATA_SIZE * sizeof(JSAMPLE));
    outptr = (JSAMPROW)malloc(DATA_SIZE * 4 * sizeof(JSAMPLE));

    range_limit = (JSAMPLE*)malloc(512 * sizeof(JSAMPLE));
    for (int i = 0; i < 512; i++) {
        range_limit[i] = (JSAMPLE)((i < 0) ? 0 : (i > 255) ? 255 : i);
    }

    Crrtab = (int*)malloc(256 * sizeof(int));
    Cbbtab = (int*)malloc(256 * sizeof(int));
    Crgtab = (INT32*)malloc(256 * sizeof(INT32));
    Cbgtab = (INT32*)malloc(256 * sizeof(INT32));

    for (int i = 0; i < 256; i++) {
        Crrtab[i] = i * 1;
        Cbbtab[i] = i * 1;
        Crgtab[i] = i * (1 << 16) / 2;
        Cbgtab[i] = i * (1 << 16) / 2;
    }

    for (JDIMENSION i = 0; i < num_cols; i++) {
        inptr0[i] = (JSAMPLE)(i % 256);
        inptr1[i] = (JSAMPLE)(i % 256);
        inptr2[i] = (JSAMPLE)(i % 256);
        inptr3[i] = (JSAMPLE)(i % 256);
    }
}