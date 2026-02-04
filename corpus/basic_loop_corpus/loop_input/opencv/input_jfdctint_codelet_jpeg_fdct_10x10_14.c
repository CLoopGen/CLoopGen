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

JSAMPLE *sample_data_base[16];
JSAMPARRAY sample_data = sample_data_base;
JDIMENSION start_col = 0;
INT32 tmp0, tmp1, tmp2, tmp3, tmp4, tmp10, tmp11, tmp12, tmp13, tmp14;
DCTELEM workspace[16];
DCTELEM *dataptr;
JSAMPROW elemptr;
int ctr;

void init_vars() {
    const size_t total_data_size = 1 << 20; // ~1MB of data
    const int rows = 16, row_width = (total_data_size + rows - 1) / rows;

    JSAMPLE* large_data_pool = (JSAMPLE*)calloc(total_data_size, sizeof(JSAMPLE));
    if (!large_data_pool) exit(1);

    for (int i = 0; i < rows; i++) {
        sample_data[i] = &large_data_pool[i * row_width];
        for (int j = 0; j < 10; j++) {
            sample_data[i][j] = (JSAMPLE)((i * 10 + j) % 251);
        }
    }

    dataptr = workspace;
    ctr = 0;
}