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

JSAMPLE *sample_data_storage[6];
JSAMPLE sample_data_rows[6][256]; // Each row has at least 3 elements for elemptr[0], [1], [2]
JSAMPARRAY sample_data = sample_data_storage;
JDIMENSION start_col = 0;
INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
DCTELEM dataptr_storage[256 * 8]; // Large enough to allow +8 increments 6 times
DCTELEM *dataptr = dataptr_storage;
JSAMPROW elemptr;
int ctr;

void init_vars() {
    for (int i = 0; i < 6; i++) {
        sample_data[i] = sample_data_rows[i];
        for (int j = 0; j < 256; j++) {
            sample_data_rows[i][j] = (JSAMPLE)(rand() % 256);
        }
    }
    for (int i = 0; i < 256 * 8; i++) {
        dataptr_storage[i] = 0;
    }
    dataptr = dataptr_storage;
    start_col = 0;
}