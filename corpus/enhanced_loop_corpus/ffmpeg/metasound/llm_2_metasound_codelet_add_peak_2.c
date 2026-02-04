#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern  float *shape;
extern float ppc_gain;
extern float *speech;
extern int j;
extern int center;
extern  float *shape_end;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 (simulated consecutive pattern)
    int start = -width / 2;
    int end = (width + 1) / 2;
    float *speech_center = &speech[center];
    int idx;

    for (idx = 0; idx < (end - start); idx++) {
        if (shape >= shape_end) break;
        speech_center[start + idx] += ppc_gain * shape[idx];
    }
}
