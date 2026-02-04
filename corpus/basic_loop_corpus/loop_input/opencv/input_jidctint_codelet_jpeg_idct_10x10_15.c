#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long INT32;

JSAMPLE *range_limit;
JSAMPARRAY output_buf;
JDIMENSION output_col;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
INT32 tmp14;
INT32 tmp20;
INT32 tmp21;
INT32 tmp22;
INT32 tmp23;
INT32 tmp24;
INT32 z1;
INT32 z2;
INT32 z3;
INT32 z4;
int *wsptr;
JSAMPROW outptr;
int ctr;

#define DATA_SIZE (64 * 1024 * 1024)
#define WORKSPACE_SIZE (8 * 10)

static int workspace_storage[WORKSPACE_SIZE];
static JSAMPLE range_limit_array[512];
static JSAMPLE output_buffer_data[10][256];
static JSAMPROW output_rows[10];

void init_vars() {
    range_limit = &range_limit_array[256];
    
    for (int i = 0; i < 512; i++) {
        range_limit_array[i] = (JSAMPLE)((i < 0) ? 0 : (i > 255) ? 255 : i);
    }
    
    for (int i = 0; i < 10; i++) {
        output_rows[i] = output_buffer_data[i];
    }
    output_buf = output_rows;
    
    output_col = 0;
    
    for (int i = 0; i < WORKSPACE_SIZE; i++) {
        workspace_storage[i] = (i % 2) ? (1 << 10) : -(1 << 10);
    }
    wsptr = workspace_storage;
}