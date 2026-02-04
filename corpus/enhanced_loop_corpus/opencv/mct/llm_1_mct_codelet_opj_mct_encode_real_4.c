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
        for (OPJ_SIZE_T k = 0; k < 2; ++k) {
            OPJ_SIZE_T idx = i + k;
            if (idx >= n) break;
            OPJ_FLOAT32 r = c0[idx];
            OPJ_FLOAT32 g = c1[idx];
            OPJ_FLOAT32 b = c2[idx];
            OPJ_FLOAT32 y = 0.298999995F * r + 0.587000012F * g + 0.114F * b;
            OPJ_FLOAT32 u = -0.168750003F * r - 0.331259996F * g + 0.5F * b;
            OPJ_FLOAT32 v = 0.5F * r - 0.418689996F * g - 0.0813099965F * b;
            c0[idx] = y;
            c1[idx] = u;
            c2[idx] = v;
        }
    }
}
