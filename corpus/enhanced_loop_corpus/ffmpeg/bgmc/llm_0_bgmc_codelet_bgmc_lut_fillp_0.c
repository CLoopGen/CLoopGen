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
    unsigned int sx1, sx2;
    for (sx1 = 0; sx1 < 4; sx1++)
        for (sx2 = 0; sx2 < 4; sx2++)
            for (i = 0; i < (1 << (14 - 8)); i++) {
                unsigned int target = (i + 1) << (14 - (14 - 8));
                unsigned int symbol = 1 << delta;
                for (; cf_table[sx1 * 4 + sx2][symbol] > target; symbol += 1 << delta);
                *lut++ = symbol >> delta;
            }
}
