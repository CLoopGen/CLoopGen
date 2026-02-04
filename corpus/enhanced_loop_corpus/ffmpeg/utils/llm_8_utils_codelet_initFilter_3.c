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
    for (i = 0; i < *outFilterSize; i += 2) {
        if (i + 1 >= *outFilterSize) break;
        int k1 = (dstW - 1) * (*outFilterSize) + i;
        int k2 = k1 + 1;
        (*outFilter)[k1 + 1 * (*outFilterSize)] = (*outFilter)[k1];
        (*outFilter)[k1 + 2 * (*outFilterSize)] = (*outFilter)[k1];
        (*outFilter)[k1 + 3 * (*outFilterSize)] = (*outFilter)[k1];
        (*outFilter)[k2 + 1 * (*outFilterSize)] = (*outFilter)[k2];
        (*outFilter)[k2 + 2 * (*outFilterSize)] = (*outFilter)[k2];
        (*outFilter)[k2 + 3 * (*outFilterSize)] = (*outFilter)[k2];
    }
}
