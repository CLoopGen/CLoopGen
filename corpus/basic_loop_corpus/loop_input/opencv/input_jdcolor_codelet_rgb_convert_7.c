#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

JSAMPROW outptr;
JSAMPROW inptr0;
JSAMPROW inptr1;
JSAMPROW inptr2;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    num_cols = 64 * 1024 * 1024 / 3;  // ~64 million elements -> ~64MB of output data (approx. 0.01 sec on modern CPU)
    
    inptr0 = (JSAMPROW)aligned_alloc(32, sizeof(JSAMPLE) * num_cols);
    inptr1 = (JSAMPROW)aligned_alloc(32, sizeof(JSAMPLE) * num_cols);
    inptr2 = (JSAMPROW)aligned_alloc(32, sizeof(JSAMPLE) * num_cols);
    outptr = (JSAMPROW)aligned_alloc(32, sizeof(JSAMPLE) * num_cols * 3);

    for (JDIMENSION i = 0; i < num_cols; i++) {
        inptr0[i] = (JSAMPLE)(i & 0xFF);
        inptr1[i] = (JSAMPLE)((i + 1) & 0xFF);
        inptr2[i] = (JSAMPLE)((i + 2) & 0xFF);
    }

    col = 0;
}