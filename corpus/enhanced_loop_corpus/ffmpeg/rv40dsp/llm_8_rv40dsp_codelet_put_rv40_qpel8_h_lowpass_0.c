#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int h;
extern  int C1;
extern  int C2;
extern  int SHIFT;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    int offset = 0;
    for (int j = 0; j < 8; j++) {
        dst[j] = cm[(src[offset - 2] + src[offset + 3] 
                    - 5 * (src[offset - 1] + src[offset + 2]) 
                    + src[offset] * C1 + src[offset + 1] * C2 
                    + (1 << (SHIFT - 1))) >> SHIFT];
        offset++;
    }
    dst += dstStride;
    src += srcStride;
}
}
