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
    uint8_t *temp_src = src;
    uint8_t *temp_ydst = ydst;
    uint8_t *temp_udst = udst;
    uint8_t *temp_vdst = vdst;
    for (y = 0; y < height; y += 2) {
        temp_ydst += lumStride;
        temp_src += srcStride;
        temp_udst += chromStride;
        temp_vdst += chromStride;
        temp_ydst += lumStride;
        temp_src += srcStride;
    }
    // Update global pointers after loop to remove loop-carried WAW and WAR hazards
    ydst = temp_ydst;
    src = temp_src;
    udst = temp_udst;
    vdst = temp_vdst;
}
