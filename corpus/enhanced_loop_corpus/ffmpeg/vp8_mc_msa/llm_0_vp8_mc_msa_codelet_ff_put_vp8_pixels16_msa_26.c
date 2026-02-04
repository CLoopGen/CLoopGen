#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cnt = (height >> 2); cnt--;) {
        for (int inner = 0; inner < 1; inner++) {
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            src += (4 * src_stride);
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            dst += (4 * dst_stride);
        }
    }
}
