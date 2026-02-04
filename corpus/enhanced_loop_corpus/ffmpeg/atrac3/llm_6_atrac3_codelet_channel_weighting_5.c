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
    float temp_w0, temp_w1;
    for (nsample = band; nsample < band + 8; nsample++) {
        float alpha = (nsample - band) * 0.125;
        temp_w0 = w[0][0] + alpha * (w[0][1] - w[0][0]);
        temp_w1 = w[1][0] + alpha * (w[1][1] - w[1][0]);
        su1[nsample] *= temp_w0;
        su2[nsample] *= temp_w1;
    }
    for (; nsample < band + 256; nsample++) {
        su1[nsample] *= w[1][0];
        su2[nsample] *= w[1][1];
    }
}
}
