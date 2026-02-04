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
    int local_idx = idx;
    uint16_t shift_val = (decode_precision == 10) ? (alpha_val >> 6) : (alpha_val >> 4);
    for (i = 0; i < val; i++) {
        dst[local_idx] = shift_val;
        local_idx++;
    }
    idx = local_idx;
}
