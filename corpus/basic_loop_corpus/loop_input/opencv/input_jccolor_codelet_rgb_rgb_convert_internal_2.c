#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

JSAMPLE *inptr;
JSAMPROW outptr0;
JSAMPROW outptr1;
JSAMPROW outptr2;
JDIMENSION col;
JDIMENSION num_cols;

#define DATA_SIZE (64 * 1024 * 1024)

JSAMPLE in_data[DATA_SIZE];
JSAMPLE out_data0[DATA_SIZE / 3];
JSAMPLE out_data1[DATA_SIZE / 3];
JSAMPLE out_data2[DATA_SIZE / 3];

void init_vars() {
    num_cols = DATA_SIZE / 3;

    inptr = in_data;
    outptr0 = out_data0;
    outptr1 = out_data1;
    outptr2 = out_data2;

    for (size_t i = 0; i < DATA_SIZE; i++) {
        in_data[i] = (JSAMPLE)(i % 256);
    }
}