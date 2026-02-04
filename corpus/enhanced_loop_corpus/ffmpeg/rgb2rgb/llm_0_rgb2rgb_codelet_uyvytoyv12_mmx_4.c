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
    for (int outer = 0; outer < height; outer += 4) {
        for (int inner = 0; inner < 2 && (outer + inner * 2) < height; inner++) {
            ydst += lumStride;
            src += srcStride;
            udst += chromStride;
            vdst += chromStride;
            ydst += lumStride;
            src += srcStride;
        }
    }
}
