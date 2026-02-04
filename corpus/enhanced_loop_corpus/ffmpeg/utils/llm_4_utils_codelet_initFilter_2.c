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
    for (j = 0; j < filterSize; j++) {
        int index1 = i * filterSize + j;
        int index2 = i * filter2Size + j;
        filter[index1] = (j < filter2Size) ? filter2[index2] : 0;
        if ((flags & 524288) && j >= minFilterSize)
            filter[index1] = 0;
    }
}
}
