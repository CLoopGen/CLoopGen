#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **filterPos;
extern int dstW;
extern int i;
extern int filter2Size;
extern int minFilterSize;
extern int64_t *filter2;
extern  int64_t fone;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = dstW - 1; i >= 0; i--) {
    int min = filter2Size;
    int j;
    int64_t cutOff = 0;
    int shift = i * filter2Size;

    for (j = 0; j < filter2Size; j += 2) {
        int64_t val1 = filter2[shift + j];
        int64_t abs1 = val1 >= 0 ? val1 : -val1;
        cutOff += abs1;

        if (j + 1 < filter2Size) {
            int64_t val2 = filter2[shift + j + 1];
            int64_t abs2 = val2 >= 0 ? val2 : -val2;
            cutOff += abs2;
        }

        if (cutOff > 0.002 * fone)
            break;

        if (i < dstW - 1 && (*filterPos)[i] >= (*filterPos)[i + 1])
            break;

        for (int k = j; k < filter2Size - 1; k++) {
            filter2[shift + k] = filter2[shift + k + 1];
        }
        filter2[shift + filter2Size - 1] = 0;
        (*filterPos)[i]++;
    }

    cutOff = 0;
    int threshold_reached = 0;
    for (j = filter2Size - 1; j > 0 && !threshold_reached; j--) {
        int64_t val = filter2[shift + j];
        cutOff += val >= 0 ? val : -val;
        if (cutOff > 0.002 * fone)
            threshold_reached = 1;
        else
            min--;
    }

    if (min > minFilterSize)
        minFilterSize = min;
}
}
