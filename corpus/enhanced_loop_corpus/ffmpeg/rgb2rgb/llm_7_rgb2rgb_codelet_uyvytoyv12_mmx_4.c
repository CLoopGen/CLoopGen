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
    uint8_t *local_ydst = ydst;
    uint8_t *local_src = src;
    uint8_t *local_udst = udst;
    uint8_t *local_vdst = vdst;
    int i;
    for (i = 0; i < height; i += 2) {
        local_src += srcStride;
        local_ydst += lumStride;
        local_src += srcStride;
        local_ydst += lumStride;
        local_udst += chromStride;
        local_vdst += chromStride;
    }
    ydst = local_ydst;
    src = local_src;
    udst = local_udst;
    vdst = local_vdst;
}
