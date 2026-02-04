#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long BLASLONG;

BLASLONG row = 1024;
BLASLONG col = 1024;
float *src;
BLASLONG srcdim = 1024;
float *dest;
BLASLONG i;
BLASLONG j;
BLASLONG ii;
float *src0;
float *src1;
float *src2;
float *src3;
float *dest0;
float *dest1;
float *dest2;
float *dest4;

void init_vars() {
    size_t src_size = (row * 4 + 8) * srcdim * sizeof(float);
    src = (float*)aligned_alloc(64, src_size);
    memset(src, 0, src_size);

    size_t dest_size = row * col * 16 * sizeof(float);
    dest = (float*)aligned_alloc(64, dest_size);
    memset(dest, 0, dest_size);

    dest1 = dest + 1;
    dest2 = dest + 2;
    dest4 = dest + 4;
}