#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *output;
extern  float *input;
extern  float iir[5][4];
extern float hist[5][2];
extern ptrdiff_t factor;
extern float res;
extern float tmp;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i++) {
    res = *input++;
    float local_hist[5][2];
    for (k = 0; k < 5; k++) {
        local_hist[k][0] = hist[k][0];
        local_hist[k][1] = hist[k][1];
    }
    for (j = 0; j < factor; j++) {
        for (k = 0; k < 5; k++) {
            tmp = local_hist[k][0] * iir[k][0] + local_hist[k][1] * iir[k][1] + res;
            res = local_hist[k][0] * iir[k][2] + local_hist[k][1] * iir[k][3] + tmp;
            local_hist[k][0] = local_hist[k][1];
            local_hist[k][1] = tmp;
        }
        *output++ = res;
        res = 0;
    }
    for (k = 0; k < 5; k++) {
        hist[k][0] = local_hist[k][0];
        hist[k][1] = local_hist[k][1];
    }
}
}
