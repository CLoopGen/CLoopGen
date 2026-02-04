#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;

JSAMPLE *image_data_storage;
JSAMPARRAY image_data;
int num_rows;
JDIMENSION input_cols;
JSAMPROW ptr;
JSAMPLE pixval;
int count;
int row;
int numcols;

void init_vars() {
    num_rows = 4096;
    input_cols = 65536 / sizeof(JSAMPLE);
    numcols = 1024;

    size_t total_size = (size_t)num_rows * input_cols * sizeof(JSAMPLE);
    if (total_size < 1024 * 1024) {
        total_size = 1024 * 1024;
        num_rows = 1024;
        input_cols = 1024;
        numcols = 1024;
    }

    image_data_storage = (JSAMPLE*)calloc(num_rows, input_cols * sizeof(JSAMPLE));
    if (!image_data_storage) exit(1);

    image_data = (JSAMPARRAY)calloc(num_rows, sizeof(JSAMPROW));
    if (!image_data) exit(1);

    for (int i = 0; i < num_rows; i++) {
        image_data[i] = &image_data_storage[i * input_cols];
        for (JDIMENSION j = 0; j < input_cols; j++) {
            image_data[i][j] = (JSAMPLE)(i ^ j);
        }
    }

    ptr = NULL;
    pixval = 0;
    count = 0;
    row = 0;
}