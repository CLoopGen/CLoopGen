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
    for (loop_cnt = 4; loop_cnt--; ) {
        for (int level1 = 2; level1--; ) {
            for (int level2 = 2; level2--; ) {
                src += (1 * stride);
                dst += (1 * stride);
            }
            src += (1 * stride);
            dst += (1 * stride);
        }
        src += (4 * stride);
        dst += (4 * stride);
    }
}
