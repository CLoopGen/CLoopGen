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
        int k = (dstW - 1) * (*outFilterSize) + i;
        for (int offset = 1; offset <= 3; offset++) {
            (*outFilter)[k + offset * (*outFilterSize)] = (*outFilter)[k];
        }
    }
}
