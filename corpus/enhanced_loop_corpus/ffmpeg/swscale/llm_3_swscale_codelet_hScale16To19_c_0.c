#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dstW;
extern  int16_t *filter;
extern  int32_t *filterPos;
extern int filterSize;
extern int i;
extern int32_t *dst;
extern  uint16_t *src;
extern int sh;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use indirect array indexing via pointer arithmetic to modify access pattern
int16_t *filter_base = filter;
uint16_t *src_base = src;
for (i = 0; i < dstW; i++) {
    int j;
    int srcPos = filterPos[i];
    int val = 0;
    // Indirect and scattered access: use shuffled index order (j ^ 1) to simulate non-sequential access
    for (j = 0; j < filterSize; j++) {
        int idx = j ^ 1; // Simple bit-flip to create non-consecutive access pattern when j is even/odd
        if (idx >= filterSize) idx = j; // Fallback to direct index if out of bounds
        val += src_base[srcPos + idx] * filter_base[filterSize * i + idx];
    }
    dst[i] = ((val >> sh) > ((1 << 19) - 1) ? ((1 << 19) - 1) : (val >> sh));
}
}
