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

JSAMPLE *sample_data_rows[7];
JSAMPARRAY sample_data = (JSAMPARRAY)&sample_data_rows;
JDIMENSION start_col = 0;
INT32 tmp0, tmp1, tmp2, tmp3, tmp10, tmp11, tmp12, z1, z2, z3;
DCTELEM *dataptr;
JSAMPROW elemptr;
int ctr;

void init_vars() {
    const int data_size = 16 * 1024 * 1024; // ~16MB of total sample data
    JSAMPLE *sample_pool = (JSAMPLE*)calloc(data_size, sizeof(JSAMPLE));
    if (!sample_pool) {
        fprintf(stderr, "Failed to allocate sample data\n");
        exit(1);
    }

    // Initialize each row in sample_data with valid pointers
    size_t row_stride = data_size / 7;
    for (int i = 0; i < 7; i++) {
        sample_data[i] = &sample_pool[i * row_stride];
        // Ensure at least 7 elements per row are accessible
        for (int j = 0; j < 7; j++) {
            sample_data[i][j] = (JSAMPLE)((i + j) % 256);
        }
    }

    // Allocate and initialize dataptr to point to a valid DCTELEM array
    // We need at least 8 * 7 = 56 elements since dataptr += 8 happens 7 times
    DCTELEM *dct_block = (DCTELEM*)calloc(8 * 7, sizeof(DCTELEM));
    if (!dct_block) {
        fprintf(stderr, "Failed to allocate DCT block\n");
        exit(1);
    }
    dataptr = dct_block;
}