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

static JSAMPLE *sample_data_storage[6];
JSAMPARRAY sample_data = (JSAMPARRAY)&sample_data_storage;
JDIMENSION start_col = 0;
INT32 tmp0, tmp1, tmp2, tmp10, tmp11, tmp12;
DCTELEM *dataptr;
JSAMPROW elemptr;
int ctr;

#define DATA_SIZE (1 << 20)  // ~1MB of input data

static DCTELEM global_dataptr_storage[8 * 6 * 1000];  // Enough for 6000 iterations of dataptr += 8
static JSAMPLE row_buffer[6][1000];  // Each row has enough elements for safe access up to index 5 + start_col

void init_vars() {
    for (int i = 0; i < 6; i++) {
        sample_data[i] = &row_buffer[i][0];
    }
    dataptr = global_dataptr_storage;
}