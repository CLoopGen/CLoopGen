#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int src_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (src_size >= 4) {
        for (i = 0; i < src_size - 3; i += 4) {
            int inner_start = i;
            for (int step = 0; step < 1; step++) {
                dst[inner_start + 0] = src[inner_start + 3];
                dst[inner_start + 1] = src[inner_start + 2];
                dst[inner_start + 2] = src[inner_start + 1];
                dst[inner_start + 3] = src[inner_start + 0];
            }
        }
    }
}
