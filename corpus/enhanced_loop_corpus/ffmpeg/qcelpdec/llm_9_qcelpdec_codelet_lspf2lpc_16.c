#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lpc;
extern double bandwidth_expansion_coeff;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 5; i++) {
    float temp1 = lpc[i] * bandwidth_expansion_coeff;
    float temp2 = lpc[9 - i] * (bandwidth_expansion_coeff * 0.98829999999999996);
    lpc[i] = temp1;
    lpc[9 - i] = temp2;
    bandwidth_expansion_coeff *= 0.98829999999999996 * 0.98829999999999996;
}
}
