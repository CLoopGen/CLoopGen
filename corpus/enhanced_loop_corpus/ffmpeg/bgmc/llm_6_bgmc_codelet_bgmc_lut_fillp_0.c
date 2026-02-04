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
    uint16_t *cf_local = cf_table[sx];
    uint8_t *lut_local = lut + sx * (1 << (14 - 8));
    unsigned int shift_val = 14 - 8;
    unsigned int base_target_shift = 14 - shift_val;
    for (i = 0; i < (1 << shift_val); i++) {
        unsigned int target = (i + 1) << base_target_shift;
        unsigned int symbol = 1 << delta;
        unsigned int temp_symbol = symbol;
        for (int step = 0; step < (1 << (14 - delta)); step++) {
            if (temp_symbol >= (1U << 14)) break;
            if (cf_local[temp_symbol] <= target) break;
            temp_symbol += 1 << delta;
        }
        lut_local[i] = temp_symbol >> delta;
    }
}
lut += 16 * (1 << (14 - 8));
}
