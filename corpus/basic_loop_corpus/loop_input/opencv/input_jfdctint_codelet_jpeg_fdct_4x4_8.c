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

static JSAMPLE *sample_data_storage[4];
static JSAMPLE sample_rows[4][1024];
JSAMPARRAY sample_data = sample_data_storage;
JDIMENSION start_col = 0;
INT32 tmp0;
INT32 tmp1;
INT32 tmp10;
INT32 tmp11;
DCTELEM *dataptr;
JSAMPROW elemptr;
int ctr;

DCTELEM data_block[4096];

void init_vars() {
    for (int i = 0; i < 4; i++) {
        sample_data[i] = sample_rows[i];
        for (int j = 0; j < 1024; j++) {
            sample_rows[i][j] = (JSAMPLE)((i * 1000 + j) % 256);
        }
    }
    dataptr = data_block;
    start_col = 0;
}