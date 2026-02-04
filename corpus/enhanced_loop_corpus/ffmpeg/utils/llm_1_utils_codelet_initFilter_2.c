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
int k;
for (k = 0; k < dstW * filterSize; k++) {
    int i = k / filterSize;
    int j = k % filterSize;
    if (j >= filter2Size)
        filter[k] = 0;
    else
        filter[k] = filter2[i * filter2Size + j];
    if ((flags & 524288) && j >= minFilterSize)
        filter[k] = 0;
}
}
