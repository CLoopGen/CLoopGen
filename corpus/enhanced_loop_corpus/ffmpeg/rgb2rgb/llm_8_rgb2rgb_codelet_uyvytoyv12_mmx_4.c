#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *ydst;
extern uint8_t *udst;
extern uint8_t *vdst;
extern int height;
extern int lumStride;
extern int chromStride;
extern int srcStride;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < height; i += 4) {
        ydst += 2 * lumStride;
        src += 2 * srcStride;
        udst += 2 * chromStride;
        vdst += 2 * chromStride;
        ydst += 2 * lumStride;
        src += 2 * srcStride;
        if (i + 2 < height) {
            ydst += lumStride;
            src += srcStride;
            udst += chromStride;
            vdst += chromStride;
            ydst += lumStride;
            src += srcStride;
        }
    }
}
