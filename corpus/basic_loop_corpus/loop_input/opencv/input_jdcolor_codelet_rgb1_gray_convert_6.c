#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long INT32;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

int r;
int g;
int b;
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
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime
    num_cols = data_size;

    inptr0 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr1 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr2 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    outptr = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));

    Rytab = (INT32*)malloc(256 * sizeof(INT32));
    Gytab = (INT32*)malloc(256 * sizeof(INT32));
    Bytab = (INT32*)malloc(256 * sizeof(INT32));

    for (JDIMENSION i = 0; i < num_cols; i++) {
        inptr0[i] = (JSAMPLE)(i & 0xFF);
        inptr1[i] = (JSAMPLE)((i >> 8) & 0xFF);
        inptr2[i] = (JSAMPLE)((i >> 16) & 0xFF);
    }

    for (int i = 0; i < 256; i++) {
        Rytab[i] = (INT32)(i * 19595L); 
        Gytab[i] = (INT32)(i * 38470L);
        Bytab[i] = (INT32)(i * 4705L);
    }
}