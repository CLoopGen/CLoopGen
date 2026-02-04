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
    int temp_y = y;
    for (y = 0; y < height; y += 2) {
        temp_y = y + 1;
        src += srcStride * 2;
        ydst += lumStride * 2;
        udst[temp_y / 2] = src[-srcStride - 1];
        vdst[temp_y / 2] = src[-srcStride + 0];
        udst += chromStride;
        vdst += chromStride;
    }
}
