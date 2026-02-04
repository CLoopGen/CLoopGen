#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *out;
extern int stride;
extern int width;
extern int height;
extern int bpp;
extern uint8_t cols[4];
extern uint8_t grps[4];
extern uint32_t col;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_col;
    for (y = 0; y < height; y++) {
        temp_col = col; // Introduce local copy to remove loop-carried dependency on shared 'col'
        if (grps)
            cols[0] = grps[3 * (y >> 1)];
        for (x = 0; x < width; x++) {
            if (grps)
                cols[1] = grps[(x >> 1) + 1];
            out[x + y * stride] = cols[temp_col & ((1 << bpp) - 1)];
            temp_col >>= bpp; // Modify local copy instead of global 'col' — eliminates WAW and WAR hazards
        }
    }
}
