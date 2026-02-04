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
JSAMPLE *outptr;

JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024;
    num_cols = data_size / 3;

    inptr0 = (JSAMPLE*)aligned_alloc(32, num_cols * sizeof(JSAMPLE));
    inptr1 = (JSAMPLE*)aligned_alloc(32, num_cols * sizeof(JSAMPLE));
    inptr2 = (JSAMPLE*)aligned_alloc(32, num_cols * sizeof(JSAMPLE));
    outptr = (JSAMPLE*)aligned_alloc(32, 3 * num_cols * sizeof(JSAMPLE));

    for (JDIMENSION i = 0; i < num_cols; i++) {
        inptr0[i] = (JSAMPLE)(i & 0xFF);
        inptr1[i] = (JSAMPLE)((i + 1) & 0xFF);
        inptr2[i] = (JSAMPLE)((i + 2) & 0xFF);
    }

    col = 0;
}