#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;

static JSAMPLE *image_data_storage;
static JSAMPROW *image_data_rows;
JSAMPARRAY image_data;
int num_rows;
JDIMENSION input_cols;
JSAMPROW ptr;
JSAMPLE pixval;
int count;
int row;
int numcols;

void init_vars() {
    // Aim for ~64MB of data to ensure loop runs long enough (~0.01 sec on modern CPU)
    size_t target_bytes = 64 * 1024 * 1024;
    
    // Choose dimensions: let's use 4096 rows and variable columns
    num_rows = 4096;
    input_cols = (target_bytes / num_rows);
    numcols = 16; // Number of replications per row
    
    // Allocate storage for all pixel data
    image_data_storage = (JSAMPLE*)calloc(num_rows * (input_cols + numcols), sizeof(JSAMPLE));
    if (!image_data_storage) {
        exit(1);
    }
    
    // Allocate row pointers
    image_data_rows = (JSAMPROW*)malloc(num_rows * sizeof(JSAMPROW));
    if (!image_data_rows) {
        exit(1);
    }
    
    // Initialize each row pointer to point into the storage
    for (int i = 0; i < num_rows; i++) {
        image_data_rows[i] = &image_data_storage[i * (input_cols + numcols)];
        // Initialize some sample data
        for (JDIMENSION j = 0; j < input_cols; j++) {
            image_data_rows[i][j] = (JSAMPLE)((i + j) % 256);
        }
    }
    
    image_data = image_data_rows;
    
    // Initialize other variables used in loop
    ptr = NULL;
    pixval = 0;
    count = 0;
    row = 0;
}