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
INT32 tmp2;
INT32 tmp3;
INT32 tmp4;
INT32 tmp5;
INT32 tmp6;
INT32 tmp7;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
INT32 tmp14;
INT32 tmp15;
INT32 tmp16;
INT32 z1;
INT32 z2;
INT32 z3;
DCTELEM workspace[56];
DCTELEM *dataptr;
JSAMPROW elemptr;
int ctr;

#define DATA_SIZE_MB 64
#define TOTAL_PIXELS (DATA_SIZE_MB * 1024 * 1024)
#define ROWS 15
#define COLS (TOTAL_PIXELS / ROWS)

static JSAMPLE (*raw_sample_buffer)[COLS];

void init_vars() {
    raw_sample_buffer = calloc(ROWS, sizeof(*raw_sample_buffer));
    sample_data = malloc(ROWS * sizeof(JSAMPROW));
    if (!raw_sample_buffer || !sample_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            raw_sample_buffer[i][j] = (JSAMPLE)((i * COLS + j) % 256);
        }
        sample_data[i] = raw_sample_buffer[i];
    }

    start_col = 0;
    dataptr = workspace;
    elemptr = sample_data[0] + start_col;
    ctr = 0;
}