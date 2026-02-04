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
if (band_count > 0) {
    for (int i = 0; i < band_count; i += 2) {
        *(c2++) = *c1 * ratio_r;
        *(c1++) *= ratio_l;
        if (i + 1 < band_count) {
            *(c2++) = *c1 * ratio_r;
            *(c1++) *= ratio_l;
        }
    }
}
}
