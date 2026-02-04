#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int r;
extern int g;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t base_alpha = 4278190080U;
    uint32_t r_val, g_val, b_val;
    for (r = 0; r < 6; r++) {
        r_val = (r * 40 + 55) << 16;
        for (g = 0; g < 6; g++) {
            g_val = (g * 40 + 55) << 8;
            for (b = 0; b < 6; b++) {
                b_val = (b * 40 + 55);
                *pal++ = base_alpha | r_val | g_val | b_val;
            }
        }
    }
}
