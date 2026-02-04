#include <stdio.h>

#include <inttypes.h>

typedef unsigned int u32;

extern  u32 Te0[256];
extern  u32 Te1[256];
extern  u32 Te2[256];
extern  u32 Te3[256];
extern  u32 *rk;
extern u32 s0;
extern u32 s1;
extern u32 s2;
extern u32 s3;
extern u32 t0;
extern u32 t1;
extern u32 t2;
extern u32 t3;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Memory Access Pattern with Index Reordering
    // We modify access pattern by introducing a stride over a unified lookup table
    // where each original TeX[Y] becomes UnifiedTable[X*256 + Y], and we use fixed strides
    // between table bases to simulate structured strided access.

    u32 *UnifiedTableBase = Te0;  // Assume Te0, Te1, Te2, Te3 are laid out contiguously in memory
                                  // i.e., Te1 = Te0 + 256, Te2 = Te0 + 512, Te3 = Te0 + 768

    const int stride = 256;

    for (;;) {
        t0 = UnifiedTableBase[(s0 >> 24)] ^
             UnifiedTableBase[stride + ((s1 >> 16) & 255)] ^
             UnifiedTableBase[2*stride + ((s2 >> 8) & 255)] ^
             UnifiedTableBase[3*stride + (s3 & 255)] ^ rk[4];

        t1 = UnifiedTableBase[(s1 >> 24)] ^
             UnifiedTableBase[stride + ((s2 >> 16) & 255)] ^
             UnifiedTableBase[2*stride + ((s3 >> 8) & 255)] ^
             UnifiedTableBase[3*stride + (s0 & 255)] ^ rk[5];

        t2 = UnifiedTableBase[(s2 >> 24)] ^
             UnifiedTableBase[stride + ((s3 >> 16) & 255)] ^
             UnifiedTableBase[2*stride + ((s0 >> 8) & 255)] ^
             UnifiedTableBase[3*stride + (s1 & 255)] ^ rk[6];

        t3 = UnifiedTableBase[(s3 >> 24)] ^
             UnifiedTableBase[stride + ((s0 >> 16) & 255)] ^
             UnifiedTableBase[2*stride + ((s1 >> 8) & 255)] ^
             UnifiedTableBase[3*stride + (s2 & 255)] ^ rk[7];

        rk += 8;
        if (--r == 0) {
            break;
        }

        s0 = UnifiedTableBase[(t0 >> 24)] ^
             UnifiedTableBase[stride + ((t1 >> 16) & 255)] ^
             UnifiedTableBase[2*stride + ((t2 >> 8) & 255)] ^
             UnifiedTableBase[3*stride + (t3 & 255)] ^ rk[0];

        s1 = UnifiedTableBase[(t1 >> 24)] ^
             UnifiedTableBase[stride + ((t2 >> 16) & 255)] ^
             UnifiedTableBase[2*stride + ((t3 >> 8) & 255)] ^
             UnifiedTableBase[3*stride + (t0 & 255)] ^ rk[1];

        s2 = UnifiedTableBase[(t2 >> 24)] ^
             UnifiedTableBase[stride + ((t3 >> 16) & 255)] ^
             UnifiedTableBase[2*stride + ((t0 >> 8) & 255)] ^
             UnifiedTableBase[3*stride + (t1 & 255)] ^ rk[2];

        s3 = UnifiedTableBase[(t3 >> 24)] ^
             UnifiedTableBase[stride + ((t0 >> 16) & 255)] ^
             UnifiedTableBase[2*stride + ((t1 >> 8) & 255)] ^
             UnifiedTableBase[3*stride + (t2 & 255)] ^ rk[3];
    }
}
