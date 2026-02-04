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
    for (r = 0; r < 6; r++) {
        for (g = 0; g < 6; g++) {
            for (b = 0; b < 6; b++) {
                if ((r + g + b) % 2 == 0) {
                    *pal++ = 4278190080U | ((r * 40 + 55) << 16) | ((g * 40 + 55) << 8) | (b * 40 + 55);
                }
            }
        }
    }
}
