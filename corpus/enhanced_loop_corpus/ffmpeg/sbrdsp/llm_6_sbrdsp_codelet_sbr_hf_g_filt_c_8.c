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
    float temp_real, temp_imag;
    for (m = 0; m < m_max; m++) {
        temp_real = X_high[m][ixh][0] * g_filt[m];
        temp_imag = X_high[m][ixh][1] * g_filt[m];
        Y[m][0] = temp_real;
        Y[m][1] = temp_imag;
    }
}
