#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *su1;
extern float *su2;
extern int band;
extern int nsample;
extern float w[2][2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (band = 256; band < 4 * 256; band += 256) {
    float prev_su1 = su1[band];
    for (nsample = band; nsample < band + 8; nsample++) {
        float factor = (w[0][0]) + (nsample - band) * 0.125 * ((w[0][1]) - (w[0][0]));
        su1[nsample] *= factor;
        if (nsample > band) {
            su1[nsample] += prev_su1 * 0.05f; // Introduce RAW and WAW dependency: current value depends on prior iteration
        }
        prev_su1 = su1[nsample];
        su2[nsample] *= ((w[1][0]) + (nsample - band) * 0.125 * ((w[1][1]) - (w[1][0])));
    }
    for (; nsample < band + 256; nsample++) {
        su1[nsample] *= w[1][0];
        su2[nsample] *= w[1][1];
    }
}
}
