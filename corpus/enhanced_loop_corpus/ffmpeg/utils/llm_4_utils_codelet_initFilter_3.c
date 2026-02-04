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
    for (i = 0; i < *outFilterSize; i++) {
        if (i % 2 == 0) {
            int k = (dstW - 1) * (*outFilterSize) + i;
            (*outFilter)[k + 1 * (*outFilterSize)] = (*outFilter)[k];
            (*outFilter)[k + 2 * (*outFilterSize)] = (*outFilter)[k];
            (*outFilter)[k + 3 * (*outFilterSize)] = (*outFilter)[k];
        }
    }
}
