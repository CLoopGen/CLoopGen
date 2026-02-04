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
    for (y = 0; y < height; y += 4) {
        for (i = 0; i < 2; ++i) {
            ydst += lumStride;
            src += srcStride;
            udst += chromStride;
            vdst += chromStride;
        }
        for (i = 0; i < 2; ++i) {
            ydst += lumStride;
            src += srcStride;
        }
        if (y + 2 >= height) break;
    }
}
