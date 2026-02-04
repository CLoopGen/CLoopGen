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

JSAMPLE *sample_data_mem;
JSAMPARRAY sample_data;
DCTELEM workspace[24];
DCTELEM *dataptr;
JSAMPROW elemptr;
int ctr;

JDIMENSION start_col = 0;
INT32 tmp0, tmp1, tmp2, tmp3, tmp4, tmp5;
INT32 tmp10, tmp11, tmp12, tmp13, tmp14;
INT32 z1, z2, z3;

void init_vars() {
    const size_t total_size = 1 << 20; // ~1MB of data
    const int num_rows = 16;
    const int row_width = 32;

    sample_data_mem = (JSAMPLE*)calloc(total_size, 1);
    if (!sample_data_mem) exit(1);

    sample_data = (JSAMPARRAY)calloc(num_rows, sizeof(JSAMPROW));
    if (!sample_data) exit(1);

    for (int i = 0; i < num_rows; i++) {
        sample_data[i] = &sample_data_mem[i * row_width];
        for (int j = 0; j < row_width; j++) {
            sample_data[i][j] = (JSAMPLE)((i * 100 + j) % 256);
        }
    }

    dataptr = workspace;
    ctr = 0;
}