#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

JSAMPROW inptr;
JSAMPROW outptr;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    num_cols = 64 * 1024 * 1024; // ~64 million elements to ensure loop runs ~0.01s on modern CPU
    inptr = (JSAMPROW)aligned_alloc(32, num_cols * sizeof(JSAMPLE));
    outptr = (JSAMPROW)aligned_alloc(32, 3 * num_cols * sizeof(JSAMPLE));

    if (!inptr || !outptr) {
        exit(1);
    }

    for (JDIMENSION i = 0; i < num_cols; i++) {
        inptr[i] = (JSAMPLE)(i & 0xFF);
    }
}