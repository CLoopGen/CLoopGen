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
    for (i = 0; i < n; ++i) {
        OPJ_FLOAT32 y = c0[i];
        OPJ_FLOAT32 u = c1[i];
        OPJ_FLOAT32 v = c2[i];
        OPJ_FLOAT32 r = y + (v * 1.40199995F);
        OPJ_FLOAT32 g = y - (u * 0.344130009F) - (v * (0.714139997F));
        OPJ_FLOAT32 b = y + (u * 1.77199996F);
        if (r >= 0.0F && g >= 0.0F && b >= 0.0F) {
            c0[i] = r;
            c1[i] = g;
            c2[i] = b;
        } else {
            c0[i] = (r < 0.0F) ? 0.0F : r;
            c1[i] = (g < 0.0F) ? 0.0F : g;
            c2[i] = (b < 0.0F) ? 0.0F : b;
        }
    }
}
