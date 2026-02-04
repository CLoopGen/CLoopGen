#include <stdio.h>

#include <inttypes.h>

extern int num;
extern float *ret_mix;
extern int q;
extern float mix[200];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float scale = 1.5f;
    for (q = 0; q < num; q++) {
        float temp = mix[q] * scale;
        ret_mix[q] = temp + 0.1f;
    }
}
