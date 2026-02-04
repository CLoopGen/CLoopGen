#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long INT32;
typedef int DCTELEM;

// Define external variables
JSAMPARRAY sample_data;
JDIMENSION start_col = 0;
INT32 tmp0, tmp1, tmp2, tmp3, tmp4, tmp10, tmp11, tmp12, tmp13, tmp14;
DCTELEM *dataptr;
JSAMPROW elemptr;
int ctr;

#define DATA_SIZE (64 * 1024 * 1024)  // ~64MB to ensure sufficient runtime (~0.01 sec on modern CPU)
#define ROWS 5
#define COLS 10

static JSAMPLE (*sample_buffer)[COLS];
static DCTELEM *data_block;

void init_vars() {
    // Allocate large buffers to meet data size requirement
    sample_buffer = (JSAMPLE(*)[COLS])calloc(DATA_SIZE, 1);
    data_block = (DCTELEM*)calloc(DATA_SIZE, 1);

    if (!sample_buffer || !data_block) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    // Initialize sample_data as array of pointers to rows in sample_buffer
    sample_data = (JSAMPROW*)malloc(ROWS * sizeof(JSAMPROW));
    for (int i = 0; i < ROWS; i++) {
        sample_data[i] = (JSAMPLE*)&sample_buffer[i % (DATA_SIZE / COLS)];
    }

    // Initialize dataptr to point into data_block
    dataptr = data_block;

    // Ensure start_col is within bounds for accessing up to index 9
    start_col = 0;  // so that elemptr[9] is valid when COLS >= 10
}