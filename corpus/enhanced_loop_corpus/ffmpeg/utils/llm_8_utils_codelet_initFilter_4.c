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
    for (i = 0; i < dstW; i += 2) {
        if (i < dstW) {
            filter[i * filterSize] = fone;
            (*filterPos)[i] = i;
        }
        if (i + 1 < dstW) {
            filter[(i + 1) * filterSize] = fone;
            (*filterPos)[i + 1] = i + 1;
        }
    }
}
