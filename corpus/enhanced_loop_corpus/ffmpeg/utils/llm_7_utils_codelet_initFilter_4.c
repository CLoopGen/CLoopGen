#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **filterPos;
extern int dstW;
extern int filterSize;
extern int64_t *filter;
extern  int64_t fone;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp[dstW];
    for (i = 0; i < dstW; i++) {
        temp[i] = i;
    }
    for (i = 0; i < dstW; i++) {
        filter[i * filterSize] = fone;
        (*filterPos)[i] = temp[i];
    }
}
