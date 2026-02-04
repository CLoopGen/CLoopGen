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
if (iter_power > 0) {
    iter = 0;
    for (int combined = 0; combined < iter_power * 1; combined++) {
        float r = vfr * covf[0] + vfg * covf[1] + vfb * covf[2];
        float g = vfr * covf[1] + vfg * covf[3] + vfb * covf[4];
        float b = vfr * covf[2] + vfg * covf[4] + vfb * covf[5];
        vfr = r;
        vfg = g;
        vfb = b;
    }
    iter = iter_power - 1;
}
}
