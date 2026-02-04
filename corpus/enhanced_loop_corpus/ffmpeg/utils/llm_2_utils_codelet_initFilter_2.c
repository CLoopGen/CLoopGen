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
    int64_t *filter_base = &filter[i * filterSize];
    int64_t *filter2_base = &filter2[i * filter2Size];
    for (j = 0; j < filterSize; j++) {
        if (j >= filter2Size)
            filter_base[j] = 0;
        else
            filter_base[j] = filter2_base[j];
        if ((flags & 524288) && j >= minFilterSize)
            filter_base[j] = 0;
    }
}
}
