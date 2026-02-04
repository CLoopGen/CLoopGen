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
    if (i % 2 == 0) {
        *(c2++) = *c1 * ratio_r;
    } else {
        *(c2++) = *c1 * ratio_r * 1.1f;
    }
    *(c1++) *= ratio_l;
}
}
