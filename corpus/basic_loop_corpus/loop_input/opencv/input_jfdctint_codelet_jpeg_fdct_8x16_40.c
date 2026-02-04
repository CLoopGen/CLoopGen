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
JSAMPARRAY sample_data = NULL;
JDIMENSION start_col = 0;
INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
INT32 tmp3;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
INT32 z1;
DCTELEM workspace[64];
DCTELEM *dataptr;
JSAMPROW elemptr;
int ctr;

void init_vars() {
    const size_t total_size = 1 << 20; // ~1MB of input data
    const int rows = 16;
    const int row_width = 8 + start_col;

    sample_data_mem = (JSAMPLE*)calloc(total_size, sizeof(JSAMPLE));
    sample_data = (JSAMPARRAY)calloc(rows, sizeof(JSAMPROW));

    for (int i = 0; i < rows; ++i) {
        sample_data[i] = &sample_data_mem[i * row_width];
        for (int j = 0; j < 8; ++j) {
            sample_data[i][start_col + j] = (JSAMPLE)(rand() % 256);
        }
    }

    dataptr = workspace;
    ctr = 0;
}