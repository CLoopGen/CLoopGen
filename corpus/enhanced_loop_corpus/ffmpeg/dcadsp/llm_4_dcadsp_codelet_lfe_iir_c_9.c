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
        for (j = 0; j < factor; j++) {
            for (k = 0; k < 5; k++) {
                if (res > 0.0f) {
                    tmp = hist[k][0] * iir[k][0] + hist[k][1] * iir[k][1] + res;
                    res = hist[k][0] * iir[k][2] + hist[k][1] * iir[k][3] + tmp;
                    hist[k][0] = hist[k][1];
                    hist[k][1] = tmp;
                } else {
                    tmp = (hist[k][0] + hist[k][1]) * 0.5f;
                    res = tmp * iir[k][0];
                    hist[k][0] = tmp;
                    hist[k][1] = res;
                }
            }
            *output++ = res;
            res = 0;
        }
    }
}
