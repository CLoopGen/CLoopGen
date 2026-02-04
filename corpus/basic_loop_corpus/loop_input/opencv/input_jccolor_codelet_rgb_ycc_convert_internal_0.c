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
    const size_t ctab_size = 8 * (256);
    ctab = (JLONG *)calloc(ctab_size, sizeof(JLONG));
    for (size_t i = 0; i < ctab_size; i++) {
        ctab[i] = (JLONG)(i * 32768); 
    }

    num_cols = 1 << 20; 

    size_t input_size = num_cols * 3;
    inptr = (JSAMPROW)malloc(input_size * sizeof(JSAMPLE));
    for (size_t i = 0; i < input_size; i++) {
        inptr[i] = (JSAMPLE)(i % 256);
    }

    outptr0 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    outptr1 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
    outptr2 = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));

    col = 0;
}