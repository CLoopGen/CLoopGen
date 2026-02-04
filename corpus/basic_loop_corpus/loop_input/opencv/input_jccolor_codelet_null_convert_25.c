#include <stdlib.h>
#include <stdint.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

JSAMPLE *inptr;
JSAMPROW outptr0;
JSAMPROW outptr1;
JSAMPROW outptr2;
JSAMPROW outptr3;
JDIMENSION col;
JDIMENSION num_cols;

#define DATA_SIZE (64 * 1024 * 1024)

JSAMPLE in_data[DATA_SIZE];
JSAMPLE out_data0[DATA_SIZE / 4];
JSAMPLE out_data1[DATA_SIZE / 4];
JSAMPLE out_data2[DATA_SIZE / 4];
JSAMPLE out_data3[DATA_SIZE / 4];

void init_vars() {
    num_cols = DATA_SIZE / 4;

    inptr = in_data;
    outptr0 = out_data0;
    outptr1 = out_data1;
    outptr2 = out_data2;
    outptr3 = out_data3;

    for (JDIMENSION i = 0; i < DATA_SIZE; i++) {
        in_data[i] = (JSAMPLE)(i & 0xFF);
    }
}