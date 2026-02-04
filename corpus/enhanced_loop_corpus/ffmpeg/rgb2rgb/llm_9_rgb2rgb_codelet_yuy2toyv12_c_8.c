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
extern  int chromWidth;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y++) {
    int i;
    if (y % 2 == 0) {
        for (i = 0; i < chromWidth; i++) {
            uint8_t temp_y1 = src[4 * i + 0];
            uint8_t temp_u = src[4 * i + 1];
            uint8_t temp_y2 = src[4 * i + 2];
            uint8_t temp_v = src[4 * i + 3];
            ydst[2 * i + 0] = temp_y1;
            udst[i] = temp_u;
            ydst[2 * i + 1] = temp_y2;
            vdst[i] = temp_v;
        }
        ydst += lumStride;
        src += srcStride;
    } else {
        for (i = 0; i < chromWidth; i++) {
            uint8_t temp_y1 = src[4 * i + 0];
            uint8_t temp_y2 = src[4 * i + 2];
            ydst[2 * i + 0] = temp_y1;
            ydst[2 * i + 1] = temp_y2;
        }
        udst += chromStride;
        vdst += chromStride;
        ydst += lumStride;
        src += srcStride;
    }
}
}
