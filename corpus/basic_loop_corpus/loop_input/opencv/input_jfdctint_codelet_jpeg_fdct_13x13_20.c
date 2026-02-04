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

JSAMPARRAY sample_data = NULL;
JDIMENSION start_col = 0;
INT32 tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6;
INT32 tmp10, tmp11, tmp12, tmp13, tmp14, tmp15;
INT32 z1, z2;
DCTELEM workspace[40];
DCTELEM *dataptr = NULL;
JSAMPROW elemptr = NULL;
int ctr = 0;

void init_vars() {
    const size_t total_size = 1 << 20; // ~1MB of data
    const int rows = 16;
    const int row_size = total_size / rows;

    sample_data = (JSAMPARRAY)aligned_alloc(64, rows * sizeof(JSAMPROW));
    for (int i = 0; i < rows; i++) {
        sample_data[i] = (JSAMPROW)aligned_alloc(64, row_size * sizeof(JSAMPLE));
        for (int j = 0; j < row_size; j++) {
            sample_data[i][j] = (JSAMPLE)(rand() % 256);
        }
    }

    start_col = 0;
    dataptr = workspace;
    ctr = 0;
}