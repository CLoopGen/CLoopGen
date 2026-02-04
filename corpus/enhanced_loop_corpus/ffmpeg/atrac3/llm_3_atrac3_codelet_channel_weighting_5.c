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
    for (nsample = 0; nsample < 8; nsample++) {
        int idx = band + nsample;
        su1[idx] *= ((w[0][0]) + nsample * 0.125 * ((w[0][1]) - (w[0][0])));
        su2[idx] *= ((w[1][0]) + nsample * 0.125 * ((w[1][1]) - (w[1][0])));
    }
    for (nsample = 8; nsample < 256; nsample++) {
        int idx = band + nsample;
        su1[idx] *= w[1][0];
        su2[idx] *= w[1][1];
    }
}
}
