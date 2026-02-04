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
    for (i = 0; i < 2; i++) {
        int temp_diff = ff_silk_stereo_weights[wi[i] + 1] - ff_silk_stereo_weights[wi[i]];
        int weight_factor = (temp_diff * 6554) >> 16;
        int offset = ws[i] * 2 + 1;

        if (weight_factor > 0) {
            w[i] = ff_silk_stereo_weights[wi[i]] + weight_factor * offset;
        } else {
            w[i] = ff_silk_stereo_weights[wi[i]];
        }
    }
}
