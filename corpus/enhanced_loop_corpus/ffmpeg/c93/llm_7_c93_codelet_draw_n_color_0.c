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
    uint8_t local_cols[4];
    uint32_t temp_col;
    for (y = 0; y < height; y++) {
        temp_col = col;
        // Introduce artificial dependency: current row depends on previous row's cols[0]
        if (y > 0 && grps)
            local_cols[0] = cols[0] ^ grps[3 * (y >> 1)]; // Combine prior state with new lookup
        else if (grps)
            local_cols[0] = grps[3 * (y >> 1)];
        
        for (x = 0; x < width; x++) {
            if (grps)
                local_cols[1] = grps[(x >> 1) + 1] ^ local_cols[0]; // Add RAW dependency on local_cols[0]
            out[x + y * stride] = local_cols[temp_col & ((1 << bpp) - 1)];
            temp_col >>= bpp;
        }
        // Propagate a value forward to create loop-carried dependency
        cols[0] = local_cols[1]; // Write back to global state — creates loop-carried WAW/RAW
    }
}
