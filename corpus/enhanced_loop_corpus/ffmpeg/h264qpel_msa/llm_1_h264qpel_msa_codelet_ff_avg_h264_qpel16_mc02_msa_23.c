#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = 2; loop_cnt--; ) {
        for (int i = 0; i < 2; ++i) {
            {
            }
            ;
            src += (4 * stride);
        }
        for (int i = 0; i < 2; ++i) {
            {
            }
            ;
            dst += (4 * stride);
        }
    }
}
