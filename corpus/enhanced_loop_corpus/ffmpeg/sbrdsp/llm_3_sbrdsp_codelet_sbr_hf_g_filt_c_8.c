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
    // Variant 2: Indirect array access using pointer arithmetic to simulate indirect indexing
    // This variant uses base pointers and byte offsets to access array elements,
    // simulating a more complex memory access pattern that might occur in optimized or transformed code.
    float *base_X = &X_high[0][ixh][0];
    ptrdiff_t stride_X = 40 * 2 * sizeof(float) / sizeof(float); // distance between X_high[m][ixh][0] and X_high[m+1][ixh][0]
    float (*base_Y)[2] = Y;
    float *base_g = g_filt;

    for (m = 0; m < m_max; m++) {
        float g_val = base_g[m];
        Y[m][0] = *(base_X + m * stride_X + 0) * g_val;
        Y[m][1] = *(base_X + m * stride_X + 1) * g_val;
    }
}
