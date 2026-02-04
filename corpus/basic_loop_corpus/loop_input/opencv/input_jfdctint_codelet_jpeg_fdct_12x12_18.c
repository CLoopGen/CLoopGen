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

JSAMPLE sample_data_storage[16][256];
JSAMPROW sample_data_rows[16];
JSAMPARRAY sample_data = sample_data_rows;

JDIMENSION start_col = 0;
INT32 tmp0, tmp1, tmp2, tmp3, tmp4, tmp5;
INT32 tmp10, tmp11, tmp12, tmp13, tmp14, tmp15;
DCTELEM workspace[32];
DCTELEM *dataptr;
JSAMPROW elemptr;
int ctr = 0;

void init_vars() {
    for (int i = 0; i < 16; i++) {
        sample_data[i] = sample_data_rows[i] = sample_data_storage[i];
        for (int j = 0; j < 256; j++) {
            sample_data_storage[i][j] = (unsigned char)((i * 257 + j * 13) % 256);
        }
    }

    dataptr = workspace;
}