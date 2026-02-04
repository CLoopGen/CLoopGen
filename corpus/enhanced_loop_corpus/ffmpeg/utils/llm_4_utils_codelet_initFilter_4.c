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
    for (i = 0; i < dstW; i++) {
        if (i % 2 == 0) {
            filter[i * filterSize] = fone;
        } else {
            filter[i * filterSize] = 0;
        }
        (*filterPos)[i] = i;
    }
}
