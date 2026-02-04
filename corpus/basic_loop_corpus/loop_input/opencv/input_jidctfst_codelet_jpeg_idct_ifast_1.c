#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long JLONG;
typedef JLONG DCTELEM;

JSAMPARRAY output_buf;
JDIMENSION output_col;
DCTELEM tmp0;
DCTELEM tmp1;
DCTELEM tmp2;
DCTELEM tmp3;
DCTELEM tmp4;
DCTELEM tmp5;
DCTELEM tmp6;
DCTELEM tmp7;
DCTELEM tmp10;
DCTELEM tmp11;
DCTELEM tmp12;
DCTELEM tmp13;
DCTELEM z5;
DCTELEM z10;
DCTELEM z11;
DCTELEM z12;
DCTELEM z13;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

#define DATA_SIZE (16 * 1024 * 1024)

static JSAMPLE *output_buffer_data;
static int *workspace_data;
static JSAMPLE *range_limit_data;

void init_vars() {
    output_col = 0;

    output_buffer_data = (JSAMPLE*)calloc(DATA_SIZE, sizeof(JSAMPLE));
    workspace_data = (int*)calloc(DATA_SIZE, sizeof(int));
    range_limit_data = (JSAMPLE*)malloc((255 * 4 + 4) * sizeof(JSAMPLE));

    for (int i = 0; i < (255 * 4 + 4); i++) {
        range_limit_data[i] = (JSAMPLE)(i & 255);
    }

    output_buf = (JSAMPROW*)malloc(8 * sizeof(JSAMPROW));
    for (int i = 0; i < 8; i++) {
        output_buf[i] = &output_buffer_data[i * (DATA_SIZE / 8)];
    }

    wsptr = workspace_data;

    for (int i = 0; i < DATA_SIZE / sizeof(int); i += 8) {
        workspace_data[i + 0] = rand() % 2048 - 1024;
        workspace_data[i + 1] = rand() % 10 ? rand() % 2048 - 1024 : 0;
        workspace_data[i + 2] = rand() % 10 ? rand() % 2048 - 1024 : 0;
        workspace_data[i + 3] = rand() % 10 ? rand() % 2048 - 1024 : 0;
        workspace_data[i + 4] = rand() % 10 ? rand() % 2048 - 1024 : 0;
        workspace_data[i + 5] = rand() % 10 ? rand() % 2048 - 1024 : 0;
        workspace_data[i + 6] = rand() % 10 ? rand() % 2048 - 1024 : 0;
        workspace_data[i + 7] = rand() % 10 ? rand() % 2048 - 1024 : 0;
    }

    range_limit = range_limit_data;
}