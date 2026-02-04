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
    for (i = 0; i < 2; i += 1) {
        int base_weight = ff_silk_stereo_weights[wi[i]];
        int next_weight = ff_silk_stereo_weights[wi[i] + 1];
        int interp = ((next_weight - base_weight) * 6554LL * (ws[i] * 2 + 1)) >> 16;
        w[i] = base_weight + interp;
    }
}
