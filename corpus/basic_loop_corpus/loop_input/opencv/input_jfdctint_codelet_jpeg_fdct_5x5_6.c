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

static JSAMPLE sample_data_storage[5][256];
static JSAMPROW sample_data_rows[5];
JSAMPARRAY sample_data = sample_data_rows;
JDIMENSION start_col = 0;
INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
INT32 tmp10;
INT32 tmp11;
DCTELEM dataptr_storage[40];
DCTELEM *dataptr = dataptr_storage;
JSAMPROW elemptr;
int ctr;

void init_vars() {
    for (int i = 0; i < 5; i++) {
        sample_data[i] = sample_data_storage[i];
        for (int j = 0; j < 256; j++) {
            sample_data_storage[i][j] = (JSAMPLE)((i * 257 + j * 13) % 256);
        }
    }
    start_col = 0;
    dataptr = dataptr_storage;
}