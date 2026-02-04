#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < h + 5; i++) {
        int offset = 0;
        for (; offset < 4; offset++) {
            tmp[offset] = (src[offset] + src[offset+1]) * 20 
                        - (src[offset-1] + src[offset+2]) * 5 
                        + (src[offset-2] + src[offset+3]) + pad;
        }
        for (; offset < 8; offset++) {
            tmp[offset] = (src[offset] + src[offset+1]) * 20 
                        - (src[offset-1] + src[offset+2]) * 5 
                        + (src[offset-2] + src[offset+3]) + pad;
        }
        tmp += tmpStride;
        src += srcStride;
    }
}
