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

JSAMPLE in_buffer[DATA_SIZE];
JSAMPLE out_buffer0[DATA_SIZE / 4];
JSAMPLE out_buffer1[DATA_SIZE / 4];
JSAMPLE out_buffer2[DATA_SIZE / 4];

void init_vars() {
    num_cols = DATA_SIZE / 4;

    for (size_t i = 0; i < DATA_SIZE; i++) {
        in_buffer[i] = (JSAMPLE)(i & 0xFF);
    }

    outptr0 = out_buffer0;
    outptr1 = out_buffer1;
    outptr2 = out_buffer2;
    inptr = in_buffer;
}