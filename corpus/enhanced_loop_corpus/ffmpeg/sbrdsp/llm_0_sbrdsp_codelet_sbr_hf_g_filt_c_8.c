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
for (int i = 0; i < m_max; i++) {
    for (int j = 0; j < 1; j++) {  // Artificially increased nesting depth with a single-iteration inner loop
        Y[i][0] = X_high[i][ixh][0] * g_filt[i];
        Y[i][1] = X_high[i][ixh][1] * g_filt[i];
    }
}
}
