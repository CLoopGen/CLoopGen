#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t * cf_table[16];
extern uint8_t *lut;
extern int delta;
extern unsigned int sx;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (sx = 0; sx < 16; sx++) {
        unsigned int shift_val = 14 - 8;
        unsigned int inner_limit = 1 << shift_val;
        unsigned int base_target_shift = 14 - shift_val;
        unsigned int symbol_step = 1 << delta;
        for (i = 0; i < inner_limit; i++) {
            unsigned int target = (i + 1) << base_target_shift;
            unsigned int symbol = symbol_step;
            for (; symbol <= (1U << 14) && cf_table[sx][symbol] > target; symbol += symbol_step);
            *lut++ = symbol >> delta;
        }
    }
}
