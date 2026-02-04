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

#define DATA_SIZE (64 * 1024 * 1024)  // ~64MB input data for ~0.01 sec runtime estimate

void init_vars() {
    num_cols = DATA_SIZE;

    inptr0 = (JSAMPROW)aligned_alloc(32, num_cols * sizeof(JSAMPLE));
    inptr1 = (JSAMPROW)aligned_alloc(32, num_cols * sizeof(JSAMPLE));
    inptr2 = (JSAMPROW)aligned_alloc(32, num_cols * sizeof(JSAMPLE));
    outptr = (JSAMPROW)aligned_alloc(32, num_cols * 3 * sizeof(JSAMPLE));

    for (JDIMENSION i = 0; i < num_cols; i++) {
        inptr0[i] = rand() % 256;
        inptr1[i] = rand() % 256;
        inptr2[i] = rand() % 256;
    }

    range_limit = (JSAMPLE*)malloc(512 * sizeof(JSAMPLE));
    for (int i = 0; i < 512; i++) {
        range_limit[i] = (JSAMPLE)((i < 0) ? 0 : (i > 255) ? 255 : i);
    }

    Crrtab = (int*)malloc(256 * sizeof(int));
    Cbbtab = (int*)malloc(256 * sizeof(int));
    Crgtab = (JLONG*)malloc(256 * sizeof(JLONG));
    Cbgtab = (JLONG*)malloc(256 * sizeof(JLONG));

    for (int i = 0; i < 256; i++) {
        Crrtab[i] = i * 1;      
        Cbbtab[i] = i * 1;      
        Crgtab[i] = (JLONG)(i * 1L); 
        Cbgtab[i] = (JLONG)(i * 1L); 
    }

    col = 0;
}