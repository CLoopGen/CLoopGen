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
    for (int step = 0; step < 8; step++) {
        nsample = band + step;
        su1[nsample] *= ((w[0][0]) + step * 0.125 * ((w[0][1]) - (w[0][0])));
        su2[nsample] *= ((w[1][0]) + step * 0.125 * ((w[1][1]) - (w[1][0])));
    }
    for (int chunk = 0; chunk < 3; chunk++) {
        for (int step = 0; step < 64; step++) {
            nsample = band + 8 + chunk * 64 + step;
            su1[nsample] *= w[1][0];
            su2[nsample] *= w[1][1];
        }
    }
}
}
