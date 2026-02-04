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
JSAMPROW outptr;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    const size_t input_size = 64 * 1024 * 1024; // ~64MB of input data for sufficient runtime
    const size_t pixel_count = input_size / 4;  // each pixel takes 4 bytes (BGRA)

    num_cols = pixel_count;

    inptr = (JSAMPROW)malloc(input_size);
    outptr = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    ctab = (JLONG*)malloc(3 * (256) * sizeof(JLONG));

    if (!inptr || !outptr || !ctab) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < input_size; i++) {
        inptr[i] = (JSAMPLE)(i % 256);
    }

    for (int i = 0; i < 256; i++) {
        ctab[i + 0] = i * 1000;
        ctab[i + (1 * (255 + 1))] = i * 1200;
        ctab[i + (2 * (255 + 1))] = i * 1400;
    }
}