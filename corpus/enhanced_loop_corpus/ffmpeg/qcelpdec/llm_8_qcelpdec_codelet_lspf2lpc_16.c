#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lpc;
extern double bandwidth_expansion_coeff;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 20; i += 2) {
    lpc[i] *= bandwidth_expansion_coeff;
    if (i + 1 < 10) {
        lpc[i + 1] *= bandwidth_expansion_coeff * 0.98829999999999996;
    }
    bandwidth_expansion_coeff *= 0.98829999999999996 * 0.98829999999999996;
}
}
