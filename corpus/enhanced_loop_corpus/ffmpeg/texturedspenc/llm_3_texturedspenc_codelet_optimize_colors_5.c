#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int iter_power;
extern float covf[6];
extern float vfr;
extern float vfg;
extern float vfb;
extern int iter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (iter = 0; iter < iter_power; iter++) {
    float temp_r = vfr, temp_g = vfg, temp_b = vfb;
    float r = temp_r * covf[0] + temp_g * covf[1] + temp_b * covf[2];
    float g = temp_r * covf[1] + temp_g * covf[3] + temp_b * covf[4];
    float b = temp_r * covf[2] + temp_g * covf[4] + temp_b * covf[5];
    vfr = r;
    vfg = g;
    vfb = b;
}
}
