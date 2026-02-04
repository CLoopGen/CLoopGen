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
OPJ_FLOAT32 prev_u = 0.0F;
for (i = 0; i < n; ++i) {
    OPJ_FLOAT32 r = c0[i];
    OPJ_FLOAT32 g = c1[i];
    OPJ_FLOAT32 b = c2[i];
    // Remove write-after-write (WAW) hazard by reordering computation and introducing temporary variables
    OPJ_FLOAT32 temp_y, temp_u, temp_v;
    temp_y = 0.298999995F * r + 0.587000012F * g + 0.114F * b;
    temp_u = -0.168750003F * r - 0.331259996F * g + 0.5F * b;
    temp_v = 0.5F * r - 0.418689996F * g - 0.0813099965F * b;

    // Introduce WAR-like pattern by using current values before stores (no actual hazard due to temps)
    // Also introduce a loop-carried dependency via prev_u (RAW across iterations)
    temp_v += 0.05F * prev_u;
    prev_u = temp_u;

    c0[i] = temp_y;
    c1[i] = temp_u;
    c2[i] = temp_v;
}
}
