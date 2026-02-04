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
    int step = (height > 32) ? 4 : 1;
    for (y = 0; y < height; y += step) {
        ydst += 2 * lumStride;
        src += 2 * srcStride;
        udst += 2 * chromStride;
        vdst += 2 * chromStride;
        ydst += 2 * lumStride;
        src += 2 * srcStride;
    }
}
