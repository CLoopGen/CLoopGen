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
JDIMENSION col;
int ci;
int nc;
JDIMENSION num_cols;

void init_vars() {
    nc = 3;
    num_cols = (1 << 20) / nc;
    output_row = 0;

    input_buf = (JSAMPARRAY)malloc(num_cols * sizeof(JSAMPROW));
    JSAMPLE* input_data = (JSAMPLE*)calloc(num_cols * nc, sizeof(JSAMPLE));
    for (int i = 0; i < num_cols; i++) {
        input_buf[i] = &input_data[i * nc];
    }

    output_buf = (JSAMPIMAGE)malloc(nc * sizeof(JSAMPARRAY));
    for (int i = 0; i < nc; i++) {
        JSAMPLE* output_plane = (JSAMPLE*)malloc(num_cols * sizeof(JSAMPLE));
        output_buf[i] = (JSAMPARRAY)malloc(sizeof(JSAMPROW));
        output_buf[i][output_row] = output_plane;
    }
}