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
for (band = 256; band < 4 * 256; band += 128) {
    for (nsample = band; nsample < band + 16; nsample++) {
        float t = (nsample - band) * 0.0625f;
        su1[nsample] *= (w[0][0] * (1.0f - t) + w[0][1] * t);
        su2[nsample] *= (w[1][0] * (1.0f - t) + w[1][1] * t);
    }
    for (; nsample < band + 256; nsample += 2) {
        su1[nsample] *= w[1][0];
        su2[nsample] *= w[1][1];
        if (nsample + 1 < band + 256) {
            su1[nsample + 1] *= w[1][0];
            su2[nsample + 1] *= w[1][1];
        }
    }
}
}
