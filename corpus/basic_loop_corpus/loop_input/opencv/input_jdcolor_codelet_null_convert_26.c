#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef JSAMPARRAY *JSAMPIMAGE;
typedef unsigned int JDIMENSION;

JSAMPIMAGE input_buf;
JDIMENSION input_row;
JSAMPARRAY output_buf;
JSAMPROW inptr;
JSAMPROW outptr;
JDIMENSION col;
int num_components;
JDIMENSION num_cols;
int ci;

void init_vars() {
    num_components = 3;
    num_cols = (1 << 20) / num_components;  // ~1MB of data per component
    input_row = 0;

    input_buf = (JSAMPIMAGE)malloc(num_components * sizeof(JSAMPARRAY));
    for (int i = 0; i < num_components; i++) {
        JSAMPARRAY comp_row = (JSAMPARRAY)malloc(sizeof(JSAMPROW));
        comp_row[0] = (JSAMPROW)malloc(num_cols * sizeof(JSAMPLE));
        for (JDIMENSION j = 0; j < num_cols; j++) {
            comp_row[0][j] = (JSAMPLE)(i * 85 + j % 256);
        }
        input_buf[i] = comp_row;
    }

    size_t output_size = num_components * num_cols * sizeof(JSAMPLE);
    JSAMPROW output_data = (JSAMPROW)calloc(output_size, 1);
    output_buf = (JSAMPARRAY)malloc(sizeof(JSAMPROW));
    output_buf[0] = output_data;
}