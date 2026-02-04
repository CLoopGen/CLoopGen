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
    for (i = 0; i < n; i += 2) {
        for (OPJ_SIZE_T k = 0; k < 2 && (i + k) < n; ++k) {
            OPJ_SIZE_T idx = i + k;
            OPJ_FLOAT32 y = c0[idx];
            OPJ_FLOAT32 u = c1[idx];
            OPJ_FLOAT32 v = c2[idx];
            OPJ_FLOAT32 r = y + (v * 1.40199995F);
            OPJ_FLOAT32 g = y - (u * 0.344130009F) - (v * (0.714139997F));
            OPJ_FLOAT32 b = y + (u * 1.77199996F);
            c0[idx] = r;
            c1[idx] = g;
            c2[idx] = b;
        }
    }
}
