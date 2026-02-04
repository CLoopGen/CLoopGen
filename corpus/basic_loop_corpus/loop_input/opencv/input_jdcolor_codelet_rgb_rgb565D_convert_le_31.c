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
JSAMPLE *range_limit;
JDIMENSION num_cols;
JLONG d0;
JLONG rgb;
unsigned int r;
unsigned int g;
unsigned int b;

#define DATA_SIZE (128 << 20)  // 128 MB of input data

void init_vars() {
    num_cols = DATA_SIZE;

    range_limit = (JSAMPLE *)malloc(65536 * sizeof(JSAMPLE));
    inptr0 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr1 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    inptr2 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    outptr = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE) * 4);  // Each RGB output is 4 bytes

    for (size_t i = 0; i < 65536; i++) {
        range_limit[i] = (JSAMPLE)(i & 255);
    }
    for (size_t i = 0; i < num_cols; i++) {
        inptr0[i] = (JSAMPLE)(i % 256);
        inptr1[i] = (JSAMPLE)((i + 1) % 256);
        inptr2[i] = (JSAMPLE)((i + 2) % 256);
    }

    d0 = 0x12345678;
}