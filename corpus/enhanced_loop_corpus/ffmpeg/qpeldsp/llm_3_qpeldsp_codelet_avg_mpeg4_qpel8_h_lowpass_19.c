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
        int j;
        for (j = 0; j < 8; j++) {
            int index = ((src[j] + src[j+1]) * 20 
                       - (src[(j > 0) ? j-1 : 0] + src[j+2]) * 6 
                       + (src[(j > 1) ? j-2 : 0] + src[j+3]) * 3 
                       - (src[(j > 2) ? j-3 : 0] + src[(j < 7) ? j+4 : j+3]));
            index = (index + 16) >> 5;
            dst[j] = ((dst[j] + cm[index] + 1) >> 1);
        }
        dst += dstStride;
        src += srcStride;
    }
}
