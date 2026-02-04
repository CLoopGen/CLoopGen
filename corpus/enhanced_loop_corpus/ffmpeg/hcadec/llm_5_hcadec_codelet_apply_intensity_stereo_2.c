#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int band_count;
extern float ratio_l;
extern float ratio_r;
extern float *c1;
extern float *c2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < band_count; i++) {
    float temp = *c1;
    if (temp > 0.0f) {
        *(c2++) = temp * ratio_r;
    } else {
        *(c2++) = temp * ratio_r * -1.0f;
    }
    *(c1++) *= ratio_l;
}
}
