#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float (*Y)[2];
extern  float (*X_high)[40][2];
extern  float *g_filt;
extern int m_max;
extern intptr_t ixh;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = 0; m < m_max; m++) {
    float coeff = g_filt[m];
    if (coeff > 0.0f) {
        Y[m][0] = X_high[m][ixh][0] * coeff;
        Y[m][1] = X_high[m][ixh][1] * coeff;
    } else {
        continue;
    }
}
}
