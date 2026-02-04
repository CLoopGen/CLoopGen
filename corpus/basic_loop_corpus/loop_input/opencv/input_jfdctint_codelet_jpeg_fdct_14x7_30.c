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

#define DATA_SIZE (16 * 1024 * 1024) // ~16MB to ensure ~0.01s runtime

static JSAMPLE *sample_data_storage;
static JSAMPROW sample_data_rows[7];
JSAMPARRAY sample_data = sample_data_rows;
JDIMENSION start_col = 0;
INT32 tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6;
INT32 tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16;
DCTELEM *dataptr;
JSAMPROW elemptr;
int ctr;

void init_vars() {
    // Allocate large enough buffer to avoid bounds issues and meet size target
    sample_data_storage = (JSAMPLE*)calloc(DATA_SIZE, sizeof(JSAMPLE));
    if (!sample_data_storage) exit(1);

    // Initialize each row pointer in sample_data to point into storage
    size_t row_size = DATA_SIZE / 7;
    for (int i = 0; i < 7; i++) {
        sample_data[i] = &sample_data_storage[i * row_size];
    }

    // Ensure that elemptr[0..13] accesses are valid: need at least 14 elements per row
    if (row_size < 14) exit(1);

    // Initialize dataptr to a valid memory block of DCTELEM
    DCTELEM *data_block = (DCTELEM*)calloc(8 * 7, sizeof(DCTELEM));
    if (!data_block) exit(1);
    dataptr = data_block;

    // Optional: initialize sample_data with non-zero values for realistic computation
    for (size_t i = 0; i < DATA_SIZE; i++) {
        sample_data_storage[i] = (JSAMPLE)(i % 256);
    }
}