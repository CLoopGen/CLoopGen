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
    if (dstW > 0) {
        i = 0;
        for (int outer = 0; outer < dstW; outer++) {
            filter[outer * filterSize] = fone;
            (*filterPos)[outer] = outer;
            i++;
        }
    }
}
