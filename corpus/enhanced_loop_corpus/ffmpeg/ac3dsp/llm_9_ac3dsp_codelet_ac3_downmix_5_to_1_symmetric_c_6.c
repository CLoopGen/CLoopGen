#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **samples;
extern int len;
extern int i;
extern float front_mix;
extern float center_mix;
extern float surround_mix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < len; i++) {
        float temp1 = samples[0][i] * front_mix;
        float temp2 = samples[2][i] * front_mix;
        float temp3 = samples[3][i] * surround_mix;
        float temp4 = samples[4][i] * surround_mix;
        for (j = 0; j < 2; j++) {
            if (j == 0) {
                temp1 += samples[1][i] * center_mix;
            } else {
                samples[0][i] = temp1 + temp2 + temp3 + temp4;
            }
        }
    }
}
