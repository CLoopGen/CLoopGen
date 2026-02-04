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

JSAMPARRAY sample_data;
JDIMENSION start_col;
INT32 tmp0;
INT32 tmp1;
INT32 tmp10;
INT32 tmp11;
DCTELEM *dataptr;
JSAMPROW elemptr;
int ctr;

static JSAMPLE (*raw_sample_data)[8];
static DCTELEM *dct_block_buffer;

void init_vars() {
    size_t i;

    raw_sample_data = calloc(8, sizeof(*raw_sample_data));
    if (!raw_sample_data) exit(1);
    for (i = 0; i < 8; i++) {
        raw_sample_data[i][0] = (JSAMPLE)(i * 17 + 1);
        raw_sample_data[i][1] = (JSAMPLE)(i * 19 + 2);
        raw_sample_data[i][2] = (JSAMPLE)(i * 23 + 4);
        raw_sample_data[i][3] = (JSAMPLE)(i * 29 + 8);
        raw_sample_data[i][4] = (JSAMPLE)(i * 31 + 16);
        raw_sample_data[i][5] = (JSAMPLE)(i * 37 + 32);
        raw_sample_data[i][6] = (JSAMPLE)(i * 41 + 64);
        raw_sample_data[i][7] = (JSAMPLE)(i * 43 + 128);
    }

    sample_data = malloc(8 * sizeof(JSAMPROW));
    if (!sample_data) exit(1);
    for (i = 0; i < 8; i++) {
        sample_data[i] = raw_sample_data[i];
    }

    dct_block_buffer = calloc(64, sizeof(DCTELEM));
    if (!dct_block_buffer) exit(1);
    dataptr = dct_block_buffer;

    start_col = 0;
    tmp0 = 0;
    tmp1 = 0;
    tmp10 = 0;
    tmp11 = 0;
    elemptr = NULL;
    ctr = 0;
}