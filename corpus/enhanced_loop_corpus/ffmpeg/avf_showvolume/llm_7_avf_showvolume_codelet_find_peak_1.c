#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *src;
extern int nb_samples;
extern float *peak;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_peak = 0.0f;
    int stride = 4;
    for (i = 0; i < nb_samples - (nb_samples % stride); i += stride) {
        float v0 = src[i + 0] >= 0 ? src[i + 0] : -src[i + 0];
        float v1 = src[i + 1] >= 0 ? src[i + 1] : -src[i + 1];
        float v2 = src[i + 2] >= 0 ? src[i + 2] : -src[i + 2];
        float v3 = src[i + 3] >= 0 ? src[i + 3] : -src[i + 3];
        float max_step = v0 > v1 ? v0 : v1;
        max_step = max_step > v2 ? max_step : v2;
        max_step = max_step > v3 ? max_step : v3;
        temp_peak = temp_peak > max_step ? temp_peak : max_step;
    }
    for (; i < nb_samples; i++) {
        float abs_val = src[i] >= 0 ? src[i] : -src[i];
        temp_peak = temp_peak > abs_val ? temp_peak : abs_val;
    }
    *peak = (*peak) > temp_peak ? *peak : temp_peak;
}
