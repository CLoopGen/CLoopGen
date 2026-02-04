#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const float ff_pow_0_7[10];
extern const float ff_pow_0_55[10];
extern  float *Az;
extern float tmp1[49];
extern float tmp2[11];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10; i += 2) {
        for (int j = 0; j < 2 && (i + j) < 10; j++) {
            int idx = i + j;
            tmp1[idx + 1] = Az[idx] * ff_pow_0_55[idx];
            tmp2[idx] = Az[idx] * ff_pow_0_7[idx];
        }
    }
}
