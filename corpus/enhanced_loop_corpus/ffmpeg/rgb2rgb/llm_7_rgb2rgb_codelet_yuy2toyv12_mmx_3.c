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
    uint8_t **local_ydst = &ydst;
    uint8_t **local_src = &src;
    uint8_t **local_udst = &udst;
    uint8_t **local_vdst = &vdst;
    for (local_y = 0; local_y < height; local_y += 2) {
        // Introduce artificial RAW dependency: each update depends on prior value
        **local_ydst = (**local_ydst) + 1;  // dummy use before update
        (*local_ydst) += lumStride;
        **local_src = (**local_src) + 1;
        (*local_src) += srcStride;
        **local_udst = (**local_udst) + 1;
        (*local_udst) += chromStride;
        **local_vdst = (**local_vdst) + 1;
        (*local_vdst) += chromStride;
        (*local_ydst) += lumStride;
        (*local_src) += srcStride;
    }
}
