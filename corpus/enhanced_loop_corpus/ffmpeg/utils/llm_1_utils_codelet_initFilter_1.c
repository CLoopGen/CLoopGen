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
    int64_t cutOff = 0.;
    int unrolled_limit = filter2Size / 4 * 4; 
    int j = 0;
    for (; j < unrolled_limit; j += 4) {
        int idx_base = i * filter2Size;
        cutOff += ((filter2[idx_base]) >= 0 ? filter2[idx_base] : -filter2[idx_base]);
        if (cutOff > 0.002 * fone) break;
        if (i < dstW - 1 && (*filterPos)[i] >= (*filterPos)[i + 1]) break;

        for (int k = 0; k < filter2Size - 1; k++) {
            filter2[idx_base + k] = filter2[idx_base + k + 1];
        }
        filter2[idx_base + filter2Size - 1] = 0;
        (*filterPos)[i]++;

        if (++j >= filter2Size) break;
        cutOff += ((filter2[idx_base]) >= 0 ? filter2[idx_base] : -filter2[idx_base]);
        if (cutOff > 0.002 * fone) break;
        if (i < dstW - 1 && (*filterPos)[i] >= (*filterPos)[i + 1]) break;

        for (int k = 0; k < filter2Size - 1; k++) {
            filter2[idx_base + k] = filter2[idx_base + k + 1];
        }
        filter2[idx_base + filter2Size - 1] = 0;
        (*filterPos)[i]++;

        if (++j >= filter2Size) break;
        cutOff += ((filter2[idx_base]) >= 0 ? filter2[idx_base] : -filter2[idx_base]);
        if (cutOff > 0.002 * fone) break;
        if (i < dstW - 1 && (*filterPos)[i] >= (*filterPos)[i + 1]) break;

        for (int k = 0; k < filter2Size - 1; k++) {
            filter2[idx_base + k] = filter2[idx_base + k + 1];
        }
        filter2[idx_base + filter2Size - 1] = 0;
        (*filterPos)[i]++;

        if (++j >= filter2Size) break;
        cutOff += ((filter2[idx_base]) >= 0 ? filter2[idx_base] : -filter2[idx_base]);
        if (cutOff > 0.002 * fone) break;
        if (i < dstW - 1 && (*filterPos)[i] >= (*filterPos)[i + 1]) break;

        for (int k = 0; k < filter2Size - 1; k++) {
            filter2[idx_base + k] = filter2[idx_base + k + 1];
        }
        filter2[idx_base + filter2Size - 1] = 0;
        (*filterPos)[i]++;
        j -= 3; 
    }
    for (; j < filter2Size; j++) {
        int idx_base = i * filter2Size;
        cutOff += ((filter2[idx_base]) >= 0 ? filter2[idx_base] : -filter2[idx_base]);
        if (cutOff > 0.002 * fone) break;
        if (i < dstW - 1 && (*filterPos)[i] >= (*filterPos)[i + 1]) break;

        for (int k = 1; k < filter2Size; k++)
            filter2[idx_base + k - 1] = filter2[idx_base + k];
        filter2[idx_base + filter2Size - 1] = 0;
        (*filterPos)[i]++;
    }
    cutOff = 0;
    for (int j = filter2Size - 1; j > 0; j--) {
        cutOff += ((filter2[i * filter2Size + j]) >= 0 ? (filter2[i * filter2Size + j]) : (-(filter2[i * filter2Size + j])));
        if (cutOff > 0.002 * fone)
            break;
        min--;
    }
    if (min > minFilterSize)
        minFilterSize = min;
}
}
