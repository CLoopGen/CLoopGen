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
    int local_y;
    const int unroll_factor = 1;
    for (local_y = 0; local_y < height; local_y++) {
        ydst += lumStride;
        src += srcStride;
        if ((local_y & 1) == 1) {
            udst += chromStride;
            vdst += chromStride;
        }
        ydst += lumStride;
        src += srcStride;
    }
}
