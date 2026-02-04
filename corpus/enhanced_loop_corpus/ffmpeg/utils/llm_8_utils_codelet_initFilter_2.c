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
for (i = 0; i < dstW; i += 2) {
    int j;
    for (j = 0; j < filterSize; j++) {
        int64_t val = 0;
        if (j < filter2Size)
            val = filter2[i * filter2Size + j];
        if (!(flags & 524288) || j < minFilterSize)
            filter[i * filterSize + j] = val;
        else
            filter[i * filterSize + j] = 0;
        
        if (i + 1 < dstW) {
            int64_t val2 = (j < filter2Size) ? filter2[(i+1) * filter2Size + j] : 0;
            if ((flags & 524288) && j >= minFilterSize)
                val2 = 0;
            filter[(i+1) * filterSize + j] = val2;
        }
    }
}
}
