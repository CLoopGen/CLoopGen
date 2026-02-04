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
    uint16_t temp;
    for (i = 0; i < val; i++) {
        if (decode_precision == 10) {
            temp = (alpha_val >> 6);
        } else {
            temp = (alpha_val >> 4);
        }
        dst[idx + i] = temp;
    }
}
