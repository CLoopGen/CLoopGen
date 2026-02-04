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
    OPJ_FLOAT32 temp_r, temp_g, temp_b;
    for (i = 0; i < n; ++i) {
        OPJ_FLOAT32 y = c0[i];
        OPJ_FLOAT32 u = c1[i];
        OPJ_FLOAT32 v = c2[i];
        temp_r = y + (v * 1.40199995F);
        temp_g = y - (u * 0.344130009F) - (v * 0.714139997F);
        temp_b = y + (u * 1.77199996F);
        c0[i] = temp_r;
        c1[i] = temp_g;
        c2[i] = temp_b;
    }
}
