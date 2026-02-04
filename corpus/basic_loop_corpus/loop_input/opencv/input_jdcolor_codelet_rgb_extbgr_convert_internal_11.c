#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

JSAMPROW inptr0;
JSAMPROW inptr1;
JSAMPROW inptr2;
JSAMPROW outptr;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024;
    num_cols = data_size;

    inptr0 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr1 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr2 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    outptr = (JSAMPROW)malloc(3 * num_cols * sizeof(JSAMPLE));

    for (JDIMENSION i = 0; i < num_cols; i++) {
        inptr0[i] = (JSAMPLE)((i >> 8) & 0xFF);
        inptr1[i] = (JSAMPLE)((i >> 4) & 0xFF);
        inptr2[i] = (JSAMPLE)(i & 0xFF);
    }
}