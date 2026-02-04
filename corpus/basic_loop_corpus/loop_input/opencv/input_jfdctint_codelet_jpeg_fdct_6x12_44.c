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

JSAMPLE global_sample_data_buffer[16 * 256 * 1024]; // ~4MB of sample data
JSAMPARRAY sample_data;
JDIMENSION start_col = 0;
INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
DCTELEM workspace[32];
DCTELEM *dataptr;
JSAMPROW elemptr;
int ctr;

void init_vars() {
    // Allocate and initialize sample_data as an array of 16 rows
    const int num_rows = 16;
    sample_data = (JSAMPROW *)calloc(num_rows, sizeof(JSAMPROW));
    
    const int row_size = 256 * 1024; // 256KB per row
    for (int i = 0; i < num_rows; ++i) {
        sample_data[i] = &global_sample_data_buffer[i * row_size / num_rows];
        for (int j = 0; j < row_size / num_rows; ++j) {
            sample_data[i][j] = (JSAMPLE)((i * 31 + j * 17) % 256);
        }
    }

    // Initialize workspace to zero
    for (int i = 0; i < 32; ++i) {
        workspace[i] = 0;
    }

    // Initialize pointers and counters
    dataptr = workspace;
    ctr = 0;
}