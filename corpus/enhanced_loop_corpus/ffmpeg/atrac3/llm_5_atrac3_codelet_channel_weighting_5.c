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
for (band = 256; band < 1024; band += 256) {
    int limit1 = band + 8;
    int limit2 = band + 256;
    nsample = band;
    for (; nsample < limit2; nsample++) {
        float t = (nsample < limit1) ? ((float)(nsample - band) * 0.125) : 1.0f;
        if (nsample < limit1) {
            su1[nsample] *= ((w[0][0]) + t * ((w[0][1]) - (w[0][0])));
            su2[nsample] *= ((w[1][0]) + t * ((w[1][1]) - (w[1][0])));
        } else {
            su1[nsample] *= w[1][0];
            su2[nsample] *= w[1][1];
        }
    }
}
}
