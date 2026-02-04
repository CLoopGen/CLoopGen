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
        if (i + 1 < n) {
            OPJ_FLOAT32 r0 = c0[i], g0 = c1[i], b0 = c2[i];
            OPJ_FLOAT32 r1 = c0[i+1], g1 = c1[i+1], b1 = c2[i+1];

            OPJ_FLOAT32 y0 = 0.298999995F * r0 + 0.587000012F * g0 + 0.114F * b0;
            OPJ_FLOAT32 u0 = -0.168750003F * r0 - 0.331259996F * g0 + 0.5F * b0;
            OPJ_FLOAT32 v0 = 0.5F * r0 - 0.418689996F * g0 - 0.0813099965F * b0;

            OPJ_FLOAT32 y1 = 0.298999995F * r1 + 0.587000012F * g1 + 0.114F * b1;
            OPJ_FLOAT32 u1 = -0.168750003F * r1 - 0.331259996F * g1 + 0.5F * b1;
            OPJ_FLOAT32 v1 = 0.5F * r1 - 0.418689996F * g1 - 0.0813099965F * b1;

            c0[i] = y0; c1[i] = u0; c2[i] = v0;
            c0[i+1] = y1; c1[i+1] = u1; c2[i+1] = v1;
        } else {
            OPJ_FLOAT32 r = c0[i];
            OPJ_FLOAT32 g = c1[i];
            OPJ_FLOAT32 b = c2[i];
            OPJ_FLOAT32 y = 0.298999995F * r + 0.587000012F * g + 0.114F * b;
            OPJ_FLOAT32 u = -0.168750003F * r - 0.331259996F * g + 0.5F * b;
            OPJ_FLOAT32 v = 0.5F * r - 0.418689996F * g - 0.0813099965F * b;
            c0[i] = y;
            c1[i] = u;
            c2[i] = v;
        }
    }
}
