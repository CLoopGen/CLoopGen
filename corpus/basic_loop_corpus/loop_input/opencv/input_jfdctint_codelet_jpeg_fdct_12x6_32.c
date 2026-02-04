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

JSAMPLE *sample_data_base;
JSAMPARRAY sample_data;
JDIMENSION start_col = 0;
INT32 tmp0, tmp1, tmp2, tmp3, tmp4, tmp5;
INT32 tmp10, tmp11, tmp12, tmp13, tmp14, tmp15;
DCTELEM *dataptr_base;
DCTELEM *dataptr;
JSAMPROW elemptr;
int ctr;

void init_vars() {
    const int num_rows = 6;
    const int row_size = 12; 
    const int dct_size = 8 * num_rows;

    sample_data_base = (JSAMPLE*)calloc(num_rows * row_size, sizeof(JSAMPLE));
    sample_data = (JSAMPARRAY)calloc(num_rows, sizeof(JSAMPROW));
    dataptr_base = (DCTELEM*)calloc(dct_size, sizeof(DCTELEM));

    for (int i = 0; i < num_rows; i++) {
        sample_data[i] = &sample_data_base[i * row_size];
        for (int j = 0; j < row_size; j++) {
            sample_data[i][j] = rand() % 256;
        }
    }

    dataptr = dataptr_base;
    start_col = 0;
}