#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;

#define NUM_ROWS (65536)
#define WIDTH (128)
#define NC (4)

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
    num_rows = NUM_ROWS;
    width = WIDTH;
    nc = NC;

    input_buf = malloc(num_rows * sizeof(JSAMPROW));
    output_buf = malloc(num_rows * sizeof(JSAMPROW));
    colorindex = malloc(nc * sizeof(JSAMPROW));

    for (int i = 0; i < num_rows; i++) {
        input_buf[i] = malloc(width * sizeof(JSAMPLE));
        output_buf[i] = malloc(width * sizeof(JSAMPLE));
    }

    for (int i = 0; i < nc; i++) {
        colorindex[i] = malloc(256 * sizeof(JSAMPLE));
        for (int j = 0; j < 256; j++) {
            colorindex[i][j] = rand() % 64;
        }
    }

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < width; j++) {
            input_buf[i][j] = rand() % 256;
        }
    }
}