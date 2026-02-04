#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    int offset = 0;
    for (int j = 0; j < 8; j++) {
        dst[j] = cm[(((src[j] + src[j+1]) * 20 - (src[(j-1) >= 0 ? j-1 : 0] + src[j+2]) * 6 + 
                     (src[(j-2) >= 0 ? j-2 : 0] + src[j+3]) * 3 - (src[(j-3) >= 0 ? j-3 : 0] + src[j+4])) + 15) >> 5];
    }
    dst += dstStride;
    src += srcStride;
}
}
