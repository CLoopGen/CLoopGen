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

JSAMPLE sample_data_mem[16][256];
JSAMPROW sample_data_rows[16];
JSAMPARRAY sample_data = sample_data_rows;

JDIMENSION start_col = 0;
INT32 tmp0, tmp1, tmp2, tmp3, tmp4;
INT32 tmp10, tmp11, tmp12, tmp13;
INT32 z1, z2;
DCTELEM workspace[8];
DCTELEM *dataptr;
JSAMPROW elemptr;
int ctr = 0;

void init_vars() {
    for (int i = 0; i < 16; i++) {
        sample_data[i] = sample_data_rows[i];
        for (int j = 0; j < 256; j++) {
            sample_data_mem[i][j] = (JSAMPLE)((i + j) & 0xFF);
        }
        sample_data_rows[i] = sample_data_mem[i];
    }
    for (int i = 0; i < 8; i++) {
        workspace[i] = 0;
    }
    dataptr = workspace;
    ctr = 0;
}