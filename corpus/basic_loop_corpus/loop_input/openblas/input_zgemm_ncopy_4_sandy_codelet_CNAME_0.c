#include <stdio.h>

typedef long BLASLONG;

BLASLONG row;
BLASLONG col;
float *src;
BLASLONG srcdim;
float *dest;
BLASLONG i;
BLASLONG j;
BLASLONG ii;
float *src0;
float *src1;
float *src2;
float *src3;
float *dest0;

#define SRC_SIZE (64 * 1024 * 1024 / sizeof(float)) // ~64 MB input
#define DEST_SIZE (64 * 1024 * 1024 / sizeof(float))

static float src_data[SRC_SIZE];
static float dest_data[DEST_SIZE];

void init_vars() {
    row = 1024;
    col = 1024;
    srcdim = 2048;
    
    src = src_data;
    dest = dest_data;
    
    for (int k = 0; k < SRC_SIZE; k++) {
        src_data[k] = (float)(k % 1000) / 100.0f;
    }
}