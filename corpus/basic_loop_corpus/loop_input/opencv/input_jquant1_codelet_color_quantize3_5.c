#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;

JSAMPARRAY input_buf;
JSAMPARRAY output_buf;
int num_rows;
int pixcode;
JSAMPROW ptrin;
JSAMPROW ptrout;
JSAMPROW colorindex0;
JSAMPROW colorindex1;
JSAMPROW colorindex2;
int row;
JDIMENSION col;
JDIMENSION width;

void init_vars() {
    width = 640;
    num_rows = 256;
    size_t total_size = (size_t)width * num_rows;

    input_buf = (JSAMPARRAY)malloc(num_rows * sizeof(JSAMPROW));
    output_buf = (JSAMPARRAY)malloc(num_rows * sizeof(JSAMPROW));

    for (int i = 0; i < num_rows; i++) {
        input_buf[i] = (JSAMPROW)malloc(width * sizeof(JSAMPLE));
        output_buf[i] = (JSAMPROW)malloc(width * sizeof(JSAMPLE));
    }

    colorindex0 = (JSAMPROW)malloc(256 * sizeof(JSAMPLE));
    colorindex1 = (JSAMPROW)malloc(256 * sizeof(JSAMPLE));
    colorindex2 = (JSAMPROW)malloc(256 * sizeof(JSAMPLE));

    for (int i = 0; i < 256; i++) {
        colorindex0[i] = i;
        colorindex1[i] = i / 3;
        colorindex2[i] = i / 5;
    }

    for (int r = 0; r < num_rows; r++) {
        for (JDIMENSION c = 0; c < width; c++) {
            input_buf[r][c] = rand() % 256;
        }
    }
}