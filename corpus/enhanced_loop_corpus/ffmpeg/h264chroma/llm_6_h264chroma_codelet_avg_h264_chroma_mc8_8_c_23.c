#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t offset = 0;
    for (i = 0; i < h; i++) {
        uint8_t temp_src[8];
        for (int j = 0; j < 8; j++) {
            temp_src[j] = src[offset + j];
        }
        dst[offset]     = (((dst[offset])     + (((A * temp_src[0]) + 32) >> 6) + 1) >> 1);
        dst[offset + 1] = (((dst[offset + 1]) + (((A * temp_src[1]) + 32) >> 6) + 1) >> 1);
        dst[offset + 2] = (((dst[offset + 2]) + (((A * temp_src[2]) + 32) >> 6) + 1) >> 1);
        dst[offset + 3] = (((dst[offset + 3]) + (((A * temp_src[3]) + 32) >> 6) + 1) >> 1);
        dst[offset + 4] = (((dst[offset + 4]) + (((A * temp_src[4]) + 32) >> 6) + 1) >> 1);
        dst[offset + 5] = (((dst[offset + 5]) + (((A * temp_src[5]) + 32) >> 6) + 1) >> 1);
        dst[offset + 6] = (((dst[offset + 6]) + (((A * temp_src[6]) + 32) >> 6) + 1) >> 1);
        dst[offset + 7] = (((dst[offset + 7]) + (((A * temp_src[7]) + 32) >> 6) + 1) >> 1);
        offset += stride;
    }
}
