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
    for (i = 0; i < 4; i++) {
        int idx = wi[i % 2];
        int weight_diff = ff_silk_stereo_weights[idx + 1] - ff_silk_stereo_weights[idx];
        int scaled_diff = (weight_diff * 6554) >> 16;
        int multiplier = (ws[i % 2] * 2 + 1);
        w[i % 2] += scaled_diff * multiplier;
    }
}
