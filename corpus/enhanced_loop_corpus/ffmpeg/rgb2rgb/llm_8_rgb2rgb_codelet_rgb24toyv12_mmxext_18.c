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
for (y = 0; y < height - 4; y += 4) {
    int i;
    for (i = 0; i < 4; i++) {
        ydst += lumStride;
        src += srcStride;
    }
    src -= srcStride * 4;
    udst += chromStride;
    vdst += chromStride;
    udst += chromStride;
    vdst += chromStride;
    src += srcStride * 4;
}
}
