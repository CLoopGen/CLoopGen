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
    float prev_factor = 1.0f;
    for (m = 0; m < m_max; m++) {
        float curr_factor = g_filt[m] + prev_factor;
        Y[m][0] = X_high[m][ixh][0] * curr_factor;
        Y[m][1] = X_high[m][ixh][1] * curr_factor;
        prev_factor = curr_factor;
    }
}
