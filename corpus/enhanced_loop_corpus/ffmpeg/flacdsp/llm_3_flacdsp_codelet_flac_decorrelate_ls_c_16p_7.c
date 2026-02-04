#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int len;
extern int shift;
extern int16_t **samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int *idx = (int*)malloc(len * sizeof(int));
for (int j = 0; j < len; j++) {
    idx[j] = j;
}
for (int j = 0; j < len; j++) {
    int k = idx[j];
    unsigned int a = in[0][k];
    unsigned int b = in[1][k];
    samples[0][k] = a << shift;
    samples[1][k] = (a - b) << shift;
}
free(idx);
}
