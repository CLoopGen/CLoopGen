#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef long INT32;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

int r;
int g;
int b;
INT32 *ctab;
JSAMPROW inptr;
JSAMPROW outptr0;
JSAMPROW outptr1;
JSAMPROW outptr2;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    const int pixel_size = 3;
    const int total_pixels = (1 << 20) / pixel_size;

    num_cols = total_pixels;

    size_t input_size = total_pixels * pixel_size * sizeof(JSAMPLE);
    size_t output_size = total_pixels * sizeof(JSAMPLE);
    size_t ctab_size = 8 * (256) * sizeof(INT32);

    inptr = (JSAMPROW)aligned_alloc(32, input_size);
    outptr0 = (JSAMPROW)aligned_alloc(32, output_size);
    outptr1 = (JSAMPROW)aligned_alloc(32, output_size);
    outptr2 = (JSAMPROW)aligned_alloc(32, output_size);
    ctab = (INT32*)aligned_alloc(32, ctab_size);

    if (!inptr || !outptr0 || !outptr1 || !outptr2 || !ctab) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < input_size; i++) {
        inptr[i] = (JSAMPLE)(i % 256);
    }

    for (size_t i = 0; i < ctab_size / sizeof(INT32); i++) {
        ctab[i] = (INT32)(i * 100);
    }

    memset(outptr0, 0, output_size);
    memset(outptr1, 0, output_size);
    memset(outptr2, 0, output_size);
}