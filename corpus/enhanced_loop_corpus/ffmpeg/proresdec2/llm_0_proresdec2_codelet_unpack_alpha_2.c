#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  int decode_precision;
extern int i;
extern int idx;
extern int val;
extern int alpha_val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < val; i++) {
        if (decode_precision == 10) {
            dst[idx++] = ((alpha_val << 2) | (alpha_val >> 6));
        } else {
            dst[idx++] = ((alpha_val << 4) | (alpha_val >> 4));
        }
    }
}
