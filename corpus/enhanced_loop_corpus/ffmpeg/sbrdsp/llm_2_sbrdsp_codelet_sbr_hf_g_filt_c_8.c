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
    // Variant 1: Consecutive memory access by reordering computation to access Y and g_filt consecutively
    // We assume X_high[m][ixh] is accessed as a strided access, but we compute both components in sequence
    // to improve spatial locality in Y and reuse g_filt[m] once loaded.
    for (m = 0; m < m_max; m++) {
        float temp = g_filt[m];
        Y[m][0] = X_high[m][ixh][0] * temp;
        Y[m][1] = X_high[m][ixh][1] * temp;
    }
}
