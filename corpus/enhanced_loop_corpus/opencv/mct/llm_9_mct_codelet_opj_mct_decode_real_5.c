#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float OPJ_FLOAT32;

typedef size_t OPJ_SIZE_T;

extern OPJ_FLOAT32 *restrict c0;
extern OPJ_FLOAT32 *restrict c1;
extern OPJ_FLOAT32 *restrict c2;
extern OPJ_SIZE_T n;
extern OPJ_SIZE_T i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by processing every second element
    for (i = 0; i < n; i += 2) {
        OPJ_FLOAT32 y0 = c0[i], y1 = c0[i+1];
        OPJ_FLOAT32 u0 = c1[i], u1 = c1[i+1];
        OPJ_FLOAT32 v0 = c2[i], v1 = c2[i+1];
        
        OPJ_FLOAT32 r0 = y0 + (v0 * 1.40199995F);
        OPJ_FLOAT32 g0 = y0 - (u0 * 0.344130009F) - (v0 * 0.714139997F);
        OPJ_FLOAT32 b0 = y0 + (u0 * 1.77199996F);
        
        OPJ_FLOAT32 r1 = y1 + (v1 * 1.40199995F);
        OPJ_FLOAT32 g1 = y1 - (u1 * 0.344130009F) - (v1 * 0.714139997F);
        OPJ_FLOAT32 b1 = y1 + (u1 * 1.77199996F);
        
        c0[i] = r0; c0[i+1] = r1;
        c1[i] = g0; c1[i+1] = g1;
        c2[i] = b0; c2[i+1] = b1;
    }
    // Handle odd-sized n if needed (cleanup loop not required per constraints)
}
