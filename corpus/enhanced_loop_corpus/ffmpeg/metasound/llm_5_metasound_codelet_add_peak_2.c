#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern  float *shape;
extern float ppc_gain;
extern float *speech;
extern int j;
extern int center;
extern  float *shape_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float gain_scaled = ppc_gain;
    int lower_bound = -width / 2;
    int upper_bound = (width + 1) / 2;
    for (j = lower_bound; j < upper_bound; j++) {
        if (shape >= shape_end) break;
        int speech_idx = j + center;
        speech[speech_idx] = speech[speech_idx] + gain_scaled * (*shape);
        shape++;
    }
}
