#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;

JSAMPARRAY input_buf;
JSAMPARRAY output_buf;
int num_rows;
JSAMPARRAY colorindex;
int pixcode;
int ci;
JSAMPROW ptrin;
JSAMPROW ptrout;
int row;
JDIMENSION col;
JDIMENSION width;
int nc;

void init_vars() {
    width = 1024;
    num_rows = 256;
    nc = 3;

    input_buf = (JSAMPARRAY)malloc(num_rows * sizeof(JSAMPROW));
    output_buf = (JSAMPARRAY)malloc(num_rows * sizeof(JSAMPROW));
    colorindex = (JSAMPARRAY)malloc(nc * sizeof(JSAMPROW));

    for (int i = 0; i < num_rows; i++) {
        input_buf[i] = (JSAMPROW)malloc(width * sizeof(JSAMPLE));
        output_buf[i] = (JSAMPROW)malloc(width * sizeof(JSAMPLE));
    }

    for (int i = 0; i < nc; i++) {
        colorindex[i] = (JSAMPROW)malloc(256 * sizeof(JSAMPLE));
        for (int j = 0; j < 256; j++) {
            colorindex[i][j] = (JSAMPLE)(j ^ (i * 51));
        }
    }

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < width; j++) {
            input_buf[i][j] = (JSAMPLE)((i + j) % 256);
        }
    }
}