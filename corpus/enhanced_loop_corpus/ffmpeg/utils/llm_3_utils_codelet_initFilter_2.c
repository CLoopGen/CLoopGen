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
    for (j = 0; j < filterSize; j += 2) { // Strided access with step size 2
        int idx1 = i * filterSize + j;
        int idx2 = i * filter2Size + j;
        // Handle two elements at a time if within bounds
        if (j >= filter2Size)
            filter[idx1] = 0;
        else
            filter[idx1] = filter2[idx2];

        if ((flags & 524288) && j >= minFilterSize)
            filter[idx1] = 0;

        if (j + 1 < filterSize) {
            int idx1_next = idx1 + 1;
            int idx2_next = (j + 1 < filter2Size) ? idx2 + 1 : -1;
            if (j + 1 >= filter2Size)
                filter[idx1_next] = 0;
            else
                filter[idx1_next] = filter2[idx2_next];

            if ((flags & 524288) && j + 1 >= minFilterSize)
                filter[idx1_next] = 0;
        }
    }
}
}
