#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;
extern int16_t tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    const int t0 = tmp[i * 4 + 0];
    const int t1 = tmp[i * 4 + 1];
    const int t2 = tmp[i * 4 + 2];
    const int t3 = tmp[i * 4 + 3];
    const int p0 = t0 + t3;
    const int p1 = t1 + t2;
    const int q0 = t0 - t3;
    const int q1 = t1 - t2;
    const int r0 = p0 + p1;
    const int r1 = 2*q0 + q1;
    const int r2 = p0 - p1;
    const int r3 = q0 - 2*q1;
    coef[i * 4 + 0] = r0;
    coef[i * 4 + 1] = r1;
    coef[i * 4 + 2] = r2;
    coef[i * 4 + 3] = r3;
    
    // Additional computational work to increase intensity
    coef[i * 4 + 0] += (r1 >> 1) - (r3 >> 2);
    coef[i * 4 + 2] -= (r0 >> 1) + (r2 >> 2);
}
}
