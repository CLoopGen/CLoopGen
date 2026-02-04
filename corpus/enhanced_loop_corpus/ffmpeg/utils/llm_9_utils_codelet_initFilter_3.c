#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t **outFilter;
extern int *outFilterSize;
extern int dstW;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = (*outFilterSize) >> 2;
    if (step == 0) step = 1;
    for (i = 0; i < *outFilterSize; i += step) {
        int k = (dstW - 1) * (*outFilterSize) + i;
        int val = (*outFilter)[k];
        for (int j = 1; j <= 3; j++) {
            (*outFilter)[k + j * (*outFilterSize)] = val;
        }
    }
}
