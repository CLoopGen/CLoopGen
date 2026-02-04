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
        int offset1 = k + 1 * (*outFilterSize);
        int offset2 = k + 2 * (*outFilterSize);
        int offset3 = k + 3 * (*outFilterSize);
        int source_val = (*outFilter)[k];
        (*outFilter)[offset1] = source_val;
        (*outFilter)[offset2] = (*outFilter)[offset1]; // Introduce RAW dependency: read after write from previous line
        (*outFilter)[offset3] = (*outFilter)[offset2]; // Another RAW, chain of dependencies
    }
}
