#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int16_t ff_silk_stereo_weights[];
extern int i;
extern int wi[2];
extern int ws[2];
extern int w[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array base offset pre-computation
    const int16_t *base = ff_silk_stereo_weights;
    for (i = 0; i < 2; i++) {
        int index = wi[i];
        int diff = base[index + 1] - base[index];
        w[i] = base[index] + ((diff * 6554) >> 16) * (ws[i] * 2 + 1);
    }
}
