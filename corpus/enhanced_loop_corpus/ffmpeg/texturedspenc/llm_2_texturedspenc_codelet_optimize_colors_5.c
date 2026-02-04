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
    float r = vfr * covf[0] + vfg * covf[2] + vfb * covf[4];
    float g = vfr * covf[1] + vfg * covf[3] + vfb * covf[5];
    float b = vfr * covf[2] + vfg * covf[4] + vfb * covf[0];
    vfr = r;
    vfg = g;
    vfb = b;
}
}
