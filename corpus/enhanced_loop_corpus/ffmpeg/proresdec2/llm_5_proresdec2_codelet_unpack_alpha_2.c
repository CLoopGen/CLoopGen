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
    int shift1 = 2, shift2 = 6, shift3 = 4;
    int use_shift_pair = (decode_precision == 10);
    for (i = 0; i < val; i++) {
        int left_shift = use_shift_pair ? shift1 : shift3;
        int right_shift = use_shift_pair ? shift2 : shift3;
        dst[idx++] = (alpha_val << left_shift) | (alpha_val >> right_shift);
    }
}
