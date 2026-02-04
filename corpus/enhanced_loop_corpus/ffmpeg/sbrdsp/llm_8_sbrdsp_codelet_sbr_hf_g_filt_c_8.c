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
for (m = 0; m < m_max; m += 2) {
    if (m + 1 < m_max) {
        Y[m][0] = X_high[m][ixh][0] * g_filt[m];
        Y[m][1] = X_high[m][ixh][1] * g_filt[m];
        Y[m+1][0] = X_high[m+1][ixh][0] * g_filt[m+1];
        Y[m+1][1] = X_high[m+1][ixh][1] * g_filt[m+1];
    } else {
        Y[m][0] = X_high[m][ixh][0] * g_filt[m];
        Y[m][1] = X_high[m][ixh][1] * g_filt[m];
    }
}
}
