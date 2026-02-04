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
        idx[j] = len - 1 - j; // reverse access pattern
    }
    for (i = 0; i < len; i++) {
        int j = idx[i]; // indirect access via index mapping
        unsigned int a = in[0][j];
        int b = in[1][j];
        a -= b >> 1;
        samples[0][j] = (a + b) << shift;
        samples[1][j] = a << shift;
    }
    free(idx);
}
