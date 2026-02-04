#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long INT32;

JSAMPARRAY output_buf;
JDIMENSION output_col;
INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
INT32 tmp3;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
INT32 z1;
INT32 z2;
INT32 z3;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

#define DATA_SIZE (16 * 1024 * 1024)

static JSAMPLE *output_data;
static int *workspace;
static JSAMPLE *range_limit_data;

void init_vars() {
    output_col = 0;
    
    output_data = calloc(DATA_SIZE, sizeof(JSAMPLE));
    workspace = malloc(8 * 16 * sizeof(int));
    range_limit_data = malloc(512 * sizeof(JSAMPLE));
    
    if (!output_data || !workspace || !range_limit_data) {
        exit(1);
    }
    
    for (int i = 0; i < 512; i++) {
        range_limit_data[i] = (JSAMPLE)(i & 0xFF);
    }
    
    for (int i = 0; i < 8 * 16; i++) {
        workspace[i] = rand() - RAND_MAX / 2;
    }
    
    output_buf = malloc(16 * sizeof(JSAMPROW));
    for (int i = 0; i < 16; i++) {
        output_buf[i] = output_data + i * (DATA_SIZE / 16);
    }
    
    wsptr = workspace;
    range_limit = range_limit_data;
}