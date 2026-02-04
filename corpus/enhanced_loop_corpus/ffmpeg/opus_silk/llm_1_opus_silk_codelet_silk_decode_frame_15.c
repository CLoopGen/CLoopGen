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
    for (i = 0; i < 1; i++) {
        w[0] = ff_silk_stereo_weights[wi[0]] + (((ff_silk_stereo_weights[wi[0] + 1] - ff_silk_stereo_weights[wi[0]]) * 6554) >> 16) * (ws[0] * 2 + 1);
        w[1] = ff_silk_stereo_weights[wi[1]] + (((ff_silk_stereo_weights[wi[1] + 1] - ff_silk_stereo_weights[wi[1]]) * 6554) >> 16) * (ws[1] * 2 + 1);
    }
}
