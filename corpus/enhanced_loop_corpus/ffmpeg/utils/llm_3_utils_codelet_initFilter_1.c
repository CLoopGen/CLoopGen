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
    int *indices = (int*)alloca(filter2Size * sizeof(int));
    for (int idx = 0; idx < filter2Size; idx++) {
        indices[idx] = i * filter2Size + idx;
    }
    for (j = 0; j < filter2Size; j++) {
        int addr = indices[j];
        cutOff += ((filter2[addr]) >= 0 ? (filter2[addr]) : (-(filter2[addr])));
        if (cutOff > 0.002 * fone)
            break;
        if (i < dstW - 1 && (*filterPos)[i] >= (*filterPos)[i + 1])
            break;
        for (int k = j + 1; k < filter2Size; k++) {
            int src_addr = indices[k];
            int dst_addr = indices[k - 1];
            filter2[dst_addr] = filter2[src_addr];
        }
        filter2[indices[filter2Size - 1]] = 0;
        (*filterPos)[i]++;
    }
    cutOff = 0;
    for (j = filter2Size - 1; j > 0; j--) {
        int addr = indices[j];
        cutOff += ((filter2[addr]) >= 0 ? (filter2[addr]) : (-(filter2[addr])));
        if (cutOff > 0.002 * fone)
            break;
        min--;
    }
    if (min > minFilterSize)
        minFilterSize = min;
}
}
