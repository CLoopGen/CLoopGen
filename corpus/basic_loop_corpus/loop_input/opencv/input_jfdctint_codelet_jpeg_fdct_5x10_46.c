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

JSAMPLE *sample_data_mem = NULL;
JSAMPROW *sample_data = NULL;
JDIMENSION start_col = 0;
INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
INT32 tmp10;
INT32 tmp11;
DCTELEM workspace[16];
DCTELEM *dataptr;
JSAMPROW elemptr;
int ctr = 0;

void init_vars() {
    const size_t total_size = 1 << 20; // ~1MB of sample data
    const int num_rows = 16;
    const int row_width = (total_size + num_rows - 1) / num_rows;

    sample_data_mem = (JSAMPLE*)calloc(total_size, sizeof(JSAMPLE));
    sample_data = (JSAMPROW*)calloc(num_rows, sizeof(JSAMPROW));

    for (int i = 0; i < num_rows; i++) {
        sample_data[i] = sample_data_mem + i * row_width;
    }

    start_col = 0;
    dataptr = workspace;
    ctr = 0;
}