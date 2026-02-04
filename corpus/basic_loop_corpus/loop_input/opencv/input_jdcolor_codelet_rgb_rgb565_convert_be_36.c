#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;
typedef long JLONG;

JSAMPROW outptr;
JSAMPROW inptr0;
JSAMPROW inptr1;
JSAMPROW inptr2;
JDIMENSION col;
JDIMENSION num_cols;
JLONG rgb;
unsigned int r;
unsigned int g;
unsigned int b;

static size_t data_size = 64 * 1024 * 1024; // ~64MB of total input data

void init_vars() {
    num_cols = data_size / 3; // each pixel uses one byte per component, two pixels processed per iteration
    num_cols &= ~1U; // ensure num_cols is even so that (num_cols >> 1) iterations are safe

    inptr0 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr1 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr2 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    outptr = (JSAMPROW)malloc(num_cols * 2 * sizeof(unsigned int)); // two pixels per iteration, each 32-bit

    for (JDIMENSION i = 0; i < num_cols; i++) {
        inptr0[i] = (JSAMPLE)((i >> 8) & 255);
        inptr1[i] = (JSAMPLE)(i & 255);
        inptr2[i] = (JSAMPLE)((i * 7) & 255);
    }

    col = 0;
    rgb = 0;
    r = g = b = 0;
}