#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

JSAMPLE *inptr0;
JSAMPLE *inptr1;
JSAMPLE *inptr2;
JSAMPLE *inptr3;
JSAMPLE *outptr;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    num_cols = 64 * 1024 * 1024 / sizeof(JSAMPLE);  // ~64M elements to target ~0.01s runtime

    inptr0 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr1 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr2 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr3 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    outptr = (JSAMPROW)malloc(4 * num_cols * sizeof(JSAMPLE));

    if (!inptr0 || !inptr1 || !inptr2 || !inptr3 || !outptr) {
        exit(1);
    }

    for (JDIMENSION i = 0; i < num_cols; i++) {
        inptr0[i] = (JSAMPLE)(i & 0xFF);
        inptr1[i] = (JSAMPLE)((i + 1) & 0xFF);
        inptr2[i] = (JSAMPLE)((i + 2) & 0xFF);
        inptr3[i] = (JSAMPLE)((i + 3) & 0xFF);
    }

    col = 0;
}