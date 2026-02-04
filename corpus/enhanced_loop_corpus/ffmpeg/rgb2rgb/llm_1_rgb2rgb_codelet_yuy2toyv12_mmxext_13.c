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
    if (height > 0) {
        int y = 0;
        for (; y < height - 1; y += 2) {
            ydst += lumStride;
            src += srcStride;
            udst += chromStride;
            vdst += chromStride;
            ydst += lumStride;
            src += srcStride;
        }
        if (y < height) {
            ydst += lumStride;
            src += srcStride;
            udst += chromStride;
            vdst += chromStride;
            ydst += lumStride;
            src += srcStride;
        }
    }
}
