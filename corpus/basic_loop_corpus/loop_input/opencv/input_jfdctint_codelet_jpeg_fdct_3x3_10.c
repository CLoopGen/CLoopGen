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

static JSAMPLE *sample_data_storage[3];
static JSAMPLE sample_data_rows[3][256]; // wide enough to cover start_col + index 2
JSAMPARRAY sample_data = sample_data_storage;
JDIMENSION start_col = 0;
INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
DCTELEM *dataptr;
JSAMPROW elemptr;
int ctr;

DCTELEM data_block[24]; // 3 iterations * 8 stride

void init_vars() {
    for (int i = 0; i < 3; i++) {
        sample_data[i] = sample_data_rows[i];
        for (int j = 0; j < 256; j++) {
            sample_data_rows[i][j] = rand() % 256;
        }
    }
    dataptr = data_block;
}