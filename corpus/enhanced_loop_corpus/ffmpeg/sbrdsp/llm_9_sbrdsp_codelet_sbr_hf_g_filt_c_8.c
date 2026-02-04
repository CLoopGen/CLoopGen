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
    float temp = g_filt[m];
    float x0 = X_high[m][ixh][0];
    float x1 = X_high[m][ixh][1];
    Y[m][0] = x0 * temp;
    Y[m][1] = x1 * temp;
    Y[m][0] += x1 * temp * 0.1f;
    Y[m][1] -= x0 * temp * 0.1f;
}
}
