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
    const size_t ctab_size = 3 * (256 + 1);
    ctab = (JLONG *)calloc(ctab_size, sizeof(JLONG));
    if (!ctab) exit(1);

    const size_t input_size = 1024 * 1024 * 4; 
    JSAMPROW input_data = (JSAMPROW)calloc(input_size, sizeof(JSAMPLE));
    if (!input_data) exit(1);
    inptr = input_data;

    const size_t output_size = input_size / 4;
    JSAMPROW output_data = (JSAMPROW)calloc(output_size, sizeof(JSAMPLE));
    if (!output_data) exit(1);
    outptr = output_data;

    num_cols = output_size;

    for (size_t i = 0; i < ctab_size; i++) {
        ctab[i] = (JLONG)(i * 1000);
    }

    for (size_t i = 0; i < input_size; i++) {
        input_data[i] = (JSAMPLE)(i % 256);
    }
}