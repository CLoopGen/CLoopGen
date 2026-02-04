#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long INT32;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

INT32 y;
INT32 *Rytab;
INT32 *Gytab;
INT32 *Bytab;
JSAMPROW outptr;
JSAMPROW inptr0;
JSAMPROW inptr1;
JSAMPROW inptr2;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB for ~0.01s runtime estimate
    num_cols = data_size;

    // Allocate input and output arrays
    inptr0 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr1 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr2 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    outptr = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));

    // Allocate and initialize lookup tables (256 entries for full byte range)
    Rytab = (INT32*)malloc(256 * sizeof(INT32));
    Gytab = (INT32*)malloc(256 * sizeof(INT32));
    Bytab = (INT32*)malloc(256 * sizeof(INT32));

    for (int i = 0; i < 256; i++) {
        Rytab[i] = ((INT32)(i * 1.5)) << 16;
        Gytab[i] = ((INT32)(i * 2.0)) << 16;
        Bytab[i] = ((INT32)(i * 1.8)) << 16;
    }

    for (JDIMENSION i = 0; i < num_cols; i++) {
        inptr0[i] = rand() % 256;
        inptr1[i] = rand() % 256;
        inptr2[i] = rand() % 256;
    }

    y = 0;
    col = 0;
}