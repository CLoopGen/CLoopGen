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
if (m_max > 0) {
    // Flattened version with reduced nesting — though original is already flat, we simulate "reduction" by using a more compact form
    // using combined operations within a single loop, slightly restructured for minimalism
    for (m = 0; m < m_max; m++) {
        float tmp = g_filt[m];
        Y[m][0] = X_high[m][ixh][0] * tmp;
        Y[m][1] = X_high[m][ixh][1] * tmp;
    }
}
}
