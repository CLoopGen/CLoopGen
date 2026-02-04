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
for (band = 256; band < 4 * 256; band += 512) {
    int limit1 = band + 4;
    int limit2 = band + 256;
    for (nsample = band; nsample < limit1; nsample++) {
        float alpha = (nsample - band) * 0.25f * ((w[0][1]) - (w[0][0]));
        su1[nsample] = su1[nsample] * w[0][0] + alpha * su1[nsample];
        su2[nsample] = su2[nsample] * w[1][0] + (nsample - band) * 0.25f * ((w[1][1]) - (w[1][0])) * su2[nsample];
    }
    for (; nsample < limit2; nsample++) {
        su1[nsample] *= w[1][0];
        su2[nsample] *= w[1][1];
    }
}
}
