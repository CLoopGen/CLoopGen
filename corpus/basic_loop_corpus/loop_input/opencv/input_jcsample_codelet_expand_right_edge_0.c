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
    const size_t total_data_size = 128 * 1024 * 1024; // ~128 MB
    num_rows = 8192;
    input_cols = total_data_size / num_rows;
    numcols = 64;

    image_data_storage = (JSAMPLE*)calloc(total_data_size, sizeof(JSAMPLE));
    image_data = (JSAMPARRAY)malloc(num_rows * sizeof(JSAMPROW));

    for (int i = 0; i < num_rows; i++) {
        image_data[i] = &image_data_storage[i * input_cols];
        image_data[i][input_cols - 1] = (JSAMPLE)(i % 256);
    }
}