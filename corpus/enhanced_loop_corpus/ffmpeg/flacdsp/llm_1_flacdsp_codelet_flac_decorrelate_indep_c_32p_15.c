#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int channels;
extern int len;
extern int shift;
extern int32_t **samples;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int ij = 0; ij < channels * len; ij++) {
    i = ij / len;
    j = ij % len;
    (samples[i][j]) = (int)((unsigned int)in[i][j] << shift);
}
}
