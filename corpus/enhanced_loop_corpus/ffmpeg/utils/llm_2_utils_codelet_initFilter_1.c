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
    int64_t cutOff = 0.;
    int baseIndex = i * filter2Size;
    for (j = 0; j < filter2Size; j++) {
        cutOff += ((filter2[baseIndex + j]) >= 0 ? (filter2[baseIndex + j]) : (-(filter2[baseIndex + j])));
        if (cutOff > 0.002 * fone)
            break;
        if (i < dstW - 1 && (*filterPos)[i] >= (*filterPos)[i + 1])
            break;
        for (int k = j + 1; k < filter2Size; k++) {
            filter2[baseIndex + k - 1] = filter2[baseIndex + k];
        }
        filter2[baseIndex + filter2Size - 1] = 0;
        (*filterPos)[i]++;
    }
    cutOff = 0;
    for (j = filter2Size - 1; j > 0; j--) {
        cutOff += ((filter2[baseIndex + j]) >= 0 ? (filter2[baseIndex + j]) : (-(filter2[baseIndex + j])));
        if (cutOff > 0.002 * fone)
            break;
        min--;
    }
    if (min > minFilterSize)
        minFilterSize = min;
}
}
