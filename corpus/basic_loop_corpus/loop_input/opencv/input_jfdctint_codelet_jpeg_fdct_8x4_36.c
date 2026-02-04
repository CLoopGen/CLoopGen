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
JSAMPARRAY sample_data = sample_data_storage;
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
DCTELEM *dataptr;
JSAMPROW elemptr;
int ctr;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01s runtime
static JSAMPLE all_sample_data[4][8 + DATA_SIZE]; // each row has base + padding
static DCTELEM dct_block_storage[4 * 8];

void init_vars() {
    for (int i = 0; i < 4; i++) {
        sample_data[i] = &all_sample_data[i][0];
    }
    dataptr = dct_block_storage;
}