#include <stdio.h>

#include <inttypes.h>

typedef unsigned short uint16;

extern uint16 rm[256];
extern uint16 gm[256];
extern uint16 bm[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with loop unrolling by 4
    // This variant processes four elements per iteration to improve cache utilization and expose instruction-level parallelism
    for (i = 0; i < 256; i += 4) {
        rm[i]     = ((rm[i]     * ((1UL << 16) - 1)) / 255);
        gm[i]     = ((gm[i]     * ((1UL << 16) - 1)) / 255);
        bm[i]     = ((bm[i]     * ((1UL << 16) - 1)) / 255);
        
        if (i + 1 < 256) {
            rm[i + 1] = ((rm[i + 1] * ((1UL << 16) - 1)) / 255);
            gm[i + 1] = ((gm[i + 1] * ((1UL << 16) - 1)) / 255);
            bm[i + 1] = ((bm[i + 1] * ((1UL << 16) - 1)) / 255);
        }
        
        if (i + 2 < 256) {
            rm[i + 2] = ((rm[i + 2] * ((1UL << 16) - 1)) / 255);
            gm[i + 2] = ((gm[i + 2] * ((1UL << 16) - 1)) / 255);
            bm[i + 2] = ((bm[i + 2] * ((1UL << 16) - 1)) / 255);
        }
        
        if (i + 3 < 256) {
            rm[i + 3] = ((rm[i + 3] * ((1UL << 16) - 1)) / 255);
            gm[i + 3] = ((gm[i + 3] * ((1UL << 16) - 1)) / 255);
            bm[i + 3] = ((bm[i + 3] * ((1UL << 16) - 1)) / 255);
        }
    }
}
