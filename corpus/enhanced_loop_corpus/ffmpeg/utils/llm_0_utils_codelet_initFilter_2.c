#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dstW;
extern int flags;
extern int i;
extern int filterSize;
extern int filter2Size;
extern int minFilterSize;
extern int64_t *filter;
extern int64_t *filter2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < dstW; i++) {
    int j;
    if (filterSize > 0) {
        filter[i * filterSize] = (filter2Size > 0) ? filter2[i * filter2Size] : 0;
        for (j = 1; j < filterSize; j++) {
            if (j >= filter2Size)
                filter[i * filterSize + j] = 0;
            else
                filter[i * filterSize + j] = filter2[i * filter2Size + j];
            if ((flags & 524288) && j >= minFilterSize)
                filter[i * filterSize + j] = 0;
        }
    }
}
}
