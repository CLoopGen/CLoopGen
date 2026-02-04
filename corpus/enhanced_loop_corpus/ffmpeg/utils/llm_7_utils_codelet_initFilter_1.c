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
// Eliminate loop-carried dependency on minFilterSize by computing local minimum and updating at end
int global_min = minFilterSize;
for (i = dstW - 1; i >= 0; i--) {
    int min = filter2Size;
    int j;
    int64_t cutOff = 0;

    // Remove read-after-write (RAW) hazard by precomputing absolute sum threshold
    int threshold_index = -1;
    for (j = 0; j < filter2Size; j++) {
        int64_t val = filter2[i * filter2Size + j];
        cutOff += (val >= 0 ? val : -val);
        if (cutOff > 0.002 * fone || (i < dstW - 1 && (*filterPos)[i] >= (*filterPos)[i + 1])) {
            threshold_index = j;
            break;
        }
    }

    // If early exit condition met, perform batch left-shift using memmove-like logic without loop-carried WAW
    if (threshold_index > 0 && threshold_index < filter2Size) {
        for (j = 0; j < filter2Size - threshold_index; j++) {
            filter2[i * filter2Size + j] = filter2[i * filter2Size + j + threshold_index];
        }
        for (; j < filter2Size; j++) {
            filter2[i * filter2Size + j] = 0;
        }
        (*filterPos)[i] += threshold_index;
    }

    // Reuse cutOff for trailing accumulation, now from the end
    cutOff = 0;
    int tail_start = min - 1;
    for (j = filter2Size - 1; j >= tail_start && j > 0; j--) {
        cutOff += (filter2[i * filter2Size + j] >= 0 ? filter2[i * filter2Size + j] : -filter2[i * filter2Size + j]);
        if (cutOff > 0.002 * fone)
            break;
        min--;
    }

    // Update local min only; defer global reduction
    if (min > global_min) {
        global_min = min;
    }
}

// Final write to shared state outside per-iteration dominance
minFilterSize = global_min;
}
