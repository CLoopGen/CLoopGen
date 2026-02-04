#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef size_t OPJ_SIZE_T;

extern OPJ_INT32 *restrict c0;
extern OPJ_INT32 *restrict c1;
extern OPJ_INT32 *restrict c2;
extern OPJ_SIZE_T i;
extern  OPJ_SIZE_T len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_SIZE_T chunk_size = 4;
    OPJ_SIZE_T local_i;
    for (local_i = i; local_i < len; local_i += chunk_size) {
        OPJ_SIZE_T upper = (local_i + chunk_size < len) ? local_i + chunk_size : len;
        for (OPJ_SIZE_T k = local_i; k < upper; ++k) {
            OPJ_INT32 r = c0[k];
            OPJ_INT32 g = c1[k];
            OPJ_INT32 b = c2[k];
            OPJ_INT32 y = (r + (g * 2) + b) >> 2;
            OPJ_INT32 u = b - g;
            OPJ_INT32 v = r - g;
            c0[k] = y;
            c1[k] = u;
            c2[k] = v;
        }
    }
    i = len; // Simulate full iteration as in original
}
