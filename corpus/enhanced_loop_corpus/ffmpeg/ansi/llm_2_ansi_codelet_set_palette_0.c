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
    uint32_t *base_pal = pal;
    for (r = 0; r < 6; r++)
        for (g = 0; g < 6; g++)
            for (b = 0; b < 6; b++) {
                int index = r * 36 + g * 6 + b;
                base_pal[index] = 4278190880U | (((r) * 40 + 55) << 16) | (((g) * 40 + 55) << 8) | ((b) * 40 + 55);
            }
    pal += 216; // Advance pal pointer by total number of written elements
}
