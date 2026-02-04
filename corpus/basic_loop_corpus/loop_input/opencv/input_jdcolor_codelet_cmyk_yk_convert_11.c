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
JSAMPROW inptr3;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01 sec runtime

    num_cols = data_size;

    Rytab = (INT32*)aligned_alloc(32, sizeof(INT32) * 256);
    Gytab = (INT32*)aligned_alloc(32, sizeof(INT32) * 256);
    Bytab = (INT32*)aligned_alloc(32, sizeof(INT32) * 256);

    inptr0 = (JSAMPROW)aligned_alloc(32, data_size);
    inptr1 = (JSAMPROW)aligned_alloc(32, data_size);
    inptr2 = (JSAMPROW)aligned_alloc(32, data_size);
    inptr3 = (JSAMPROW)aligned_alloc(32, data_size);
    outptr = (JSAMPROW)aligned_alloc(32, data_size * 2); // output stride is 2 per input

    for (size_t i = 0; i < 256; i++) {
        Rytab[i] = (INT32)(i * 3);
        Gytab[i] = (INT32)(i * 2);
        Bytab[i] = (INT32)(i * 4);
    }

    for (size_t i = 0; i < data_size; i++) {
        inptr0[i] = (JSAMPLE)((i * 7) & 0xFF);
        inptr1[i] = (JSAMPLE)((i * 11) & 0xFF);
        inptr2[i] = (JSAMPLE)((i * 13) & 0xFF);
        inptr3[i] = (JSAMPLE)((i * 17) & 0xFF);
    }

    y = 0;
    col = 0;
}