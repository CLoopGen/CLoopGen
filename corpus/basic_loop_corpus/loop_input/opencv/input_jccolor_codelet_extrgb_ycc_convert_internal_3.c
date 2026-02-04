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
JSAMPROW outptr0;
JSAMPROW outptr1;
JSAMPROW outptr2;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    const JDIMENSION data_size = 8000000; // ~24MB input, ~0.01 sec estimate
    num_cols = data_size / 3;

    inptr = (JSAMPROW)malloc(data_size * sizeof(JSAMPLE));
    outptr0 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    outptr1 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    outptr2 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));

    ctab = (JLONG *)malloc(8 * (256) * sizeof(JLONG));
    for (int i = 0; i < 8 * 256; i++) {
        ctab[i] = (JLONG)(i * 1000); 
    }

    for (JDIMENSION i = 0; i < data_size; i++) {
        inptr[i] = (JSAMPLE)(i % 256);
    }

    col = 0;
}