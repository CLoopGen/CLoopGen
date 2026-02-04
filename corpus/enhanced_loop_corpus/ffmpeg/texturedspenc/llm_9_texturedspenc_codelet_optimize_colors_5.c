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
for (iter = 0; iter < iter_power; iter += 2) {
    float r1 = vfr * covf[0] + vfg * covf[1] + vfb * covf[2];
    float g1 = vfr * covf[1] + vfg * covf[3] + vfb * covf[4];
    float b1 = vfr * covf[2] + vfg * covf[4] + vfb * covf[5];
    
    float r2 = r1 * covf[0] + g1 * covf[1] + b1 * covf[2];
    float g2 = r1 * covf[1] + g1 * covf[3] + b1 * covf[4];
    float b2 = r1 * covf[2] + g1 * covf[4] + b1 * covf[5];
    
    vfr = r2;
    vfg = g2;
    vfb = b2;
    
    if (iter + 1 >= iter_power) break;
}
}
