#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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
    numcols = 16;
    
    image_data_storage = (JSAMPLE*)calloc(num_rows * (input_cols + numcols), sizeof(JSAMPLE));
    if (!image_data_storage) {
        exit(1);
    }
    
    image_data = (JSAMPARRAY)malloc(num_rows * sizeof(JSAMPROW));
    if (!image_data) {
        free(image_data_storage);
        exit(1);
    }
    
    for (int i = 0; i < num_rows; i++) {
        image_data[i] = &image_data_storage[i * (input_cols + numcols)];
        for (JDIMENSION j = 0; j < input_cols; j++) {
            image_data[i][j] = (JSAMPLE)(i + j);
        }
    }
}