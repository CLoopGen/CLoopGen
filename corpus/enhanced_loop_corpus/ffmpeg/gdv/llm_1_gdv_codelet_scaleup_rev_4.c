#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (x >= 7) {
        int temp_x = x;
        for (int outer = (temp_x - 7) >> 3; outer >= 0; --outer) {
            int inner_x = outer * 8 + 7;
            dst[inner_x + 6] = dst[inner_x + 7] = src[(inner_x >> 1) + 3];
            dst[inner_x + 4] = dst[inner_x + 5] = src[(inner_x >> 1) + 2];
            dst[inner_x + 2] = dst[inner_x + 3] = src[(inner_x >> 1) + 1];
            dst[inner_x + 0] = dst[inner_x + 1] = src[(inner_x >> 1) + 0];
        }
    }
}
