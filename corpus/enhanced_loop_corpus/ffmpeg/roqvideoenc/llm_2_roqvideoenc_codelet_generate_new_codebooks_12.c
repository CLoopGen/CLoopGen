#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int max;
extern uint8_t *yuvClusters;
extern int *points;
extern int bias;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential access, traverse yuvClusters and points with a stride of 3
    // This changes spatial locality and may affect cache performance.
    int stride = 3;
    int n = max * 24;
    for (i = 0; i < n; i += stride) {
        for (int s = 0; s < stride && (i + s) < n; s++) {
            int idx = i + s;
            bias = ((idx % 6) < 4) ? 1 : 1;
            points[idx] = bias * yuvClusters[idx];
        }
    }
}
