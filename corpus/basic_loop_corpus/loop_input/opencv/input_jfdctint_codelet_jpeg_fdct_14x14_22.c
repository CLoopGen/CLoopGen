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

JSAMPLE sample_data_buffer[14][256];  // 14 rows, each up to 256 elements to allow index 13 access
JSAMPARRAY sample_data;
DCTELEM workspace[48];
DCTELEM dataptr_storage[48];
JSAMPROW elemptr;
DCTELEM *dataptr;
JDIMENSION start_col = 0;
INT32 tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6;
INT32 tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16;
int ctr = 0;

void init_vars() {
    sample_data = (JSAMPARRAY)malloc(14 * sizeof(JSAMPROW));
    for (int i = 0; i < 14; i++) {
        sample_data[i] = &sample_data_buffer[i][0];
        for (int j = 0; j < 256; j++) {
            sample_data[i][j] = (JSAMPLE)((i * 257 + j * 13) % 256);
        }
    }
    dataptr = dataptr_storage;
    ctr = 0;
}