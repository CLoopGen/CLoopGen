#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef JSAMPARRAY *JSAMPIMAGE;
typedef unsigned int JDIMENSION;

JSAMPARRAY input_buf;
JSAMPIMAGE output_buf;
JDIMENSION output_row;
JSAMPROW inptr;
JSAMPROW outptr;
JDIMENSION count;
int num_comps;
JDIMENSION num_cols;
int ci;

void init_vars() {
    num_comps = 3;
    num_cols = 1024 * 1024 / num_comps;  // ~1MB of input data
    output_row = 0;

    input_buf = (JSAMPARRAY)calloc(1, sizeof(JSAMPROW));
    input_buf[0] = (JSAMPROW)calloc(num_cols * num_comps, sizeof(JSAMPLE));

    output_buf = (JSAMPIMAGE)calloc(num_comps, sizeof(JSAMPARRAY));
    for (int i = 0; i < num_comps; i++) {
        output_buf[i] = (JSAMPARRAY)calloc(1, sizeof(JSAMPROW));
        output_buf[i][0] = (JSAMPROW)calloc(num_cols, sizeof(JSAMPLE));
    }

    inptr = NULL;
    outptr = NULL;
    count = 0;
}