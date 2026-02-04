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
    int j = 0;
    int offset = i * filterSize;
    int offset2 = i * filter2Size;
    while (j < minFilterSize && j < filterSize) {
        filter[offset + j] = (j < filter2Size) ? filter2[offset2 + j] : 0;
        j++;
    }
    while (j < filterSize) {
        filter[offset + j] = 0;
        j++;
    }
}
}
