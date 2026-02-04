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
    const unsigned int outer_reps = 8;
    const unsigned int inner_reps = 1 << (12 - 8); 
    const unsigned int step = 2;

    for (sx = 0; sx < outer_reps; sx++) {
        for (i = 0; i < inner_reps; i += step) {
            unsigned int target_low = (i + 1) << (12 - (12 - 8));
            unsigned int target_high = (i + 2) << (12 - (12 - 8));

            unsigned int symbol = 1 << delta;
            unsigned int limit = 1U << 12;

            for (unsigned int offset = 0; offset < limit && symbol <= limit; offset += (1 << delta)) {
                if (cf_table[sx][symbol] > target_low) {
                    symbol += (1 << delta);
                }
            }
            *lut++ = symbol >> delta;

            symbol = 1 << delta;
            for (unsigned int offset = 0; offset < limit && symbol <= limit; offset += (1 << delta)) {
                if (cf_table[sx][symbol] > target_high) {
                    symbol += (1 << delta);
                }
            }
            *lut++ = symbol >> delta;
        }
    }
}
