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
INT32 tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;
INT32 tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17;
DCTELEM workspace[64];
DCTELEM *dataptr;
JSAMPROW elemptr;
int ctr;

void init_vars() {
    const int total_rows = 16;
    const int row_size = 16;
    const size_t total_data_size = total_rows * row_size;

    sample_data_mem = (JSAMPLE*)calloc(total_data_size, sizeof(JSAMPLE));
    sample_data = (JSAMPARRAY)calloc(total_rows, sizeof(JSAMPROW));

    for (int i = 0; i < total_rows; i++) {
        sample_data[i] = &sample_data_mem[i * row_size];
    }

    for (size_t i = 0; i < total_data_size; i++) {
        sample_data_mem[i] = (JSAMPLE)((i * 17 + 13) % 251);
    }

    start_col = 0;
    dataptr = workspace;
    ctr = 0;
}