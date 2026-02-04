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
    for (int j = 0; j < dstW; j++) {
        for (i = 0; i < filterSize; i++) {
            if (i == 0) {
                filter[j * filterSize + i] = fone;
                (*filterPos)[j] = j;
            }
        }
    }
}
