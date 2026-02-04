#include <stdio.h>

typedef long BLASLONG;

BLASLONG row;
BLASLONG i;
BLASLONG ii;
float *src0;
float *dest0;

static float src_buffer[65536];
static float dest_buffer[65536];

void init_vars() {
    row = 8192; 
    src0 = src_buffer;
    dest0 = dest_buffer;
    
    for (int j = 0; j < 65536; j++) {
        src_buffer[j] = (float)(j % 1000) + 0.5f;
    }
}