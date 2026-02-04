#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst1;
extern int16_t *dst2;
extern int dstWidth;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int srcW;
extern int xInc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx = i;
    for (i = dstWidth - 1; (i * xInc) >> 16 >= srcW - 1; i--) {
        int offset = srcW - 1;
        int scale = 128;
        dst1[i] = src1[offset] * scale;
        dst2[i] = src2[offset] * scale;
        // Introduced temporary variables creating new WAW and RAW dependencies within the iteration
        // Eliminated direct recomputation, added data dependency on local copies
        idx = i; // Introduce loop-carried WAW dependency on idx (though unused later, it models a potential sink)
    }
}
