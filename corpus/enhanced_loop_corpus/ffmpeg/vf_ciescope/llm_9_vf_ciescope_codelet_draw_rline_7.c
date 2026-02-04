#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t * pixels;
extern int linesize;
extern int x0;
extern int _usr_y0;
extern int x1;
extern int _usr_y1;
extern int dx;
extern int sx;
extern int dy;
extern int sy;
extern int err;
extern int e2;

// Variable name mappings to avoid conflicts with system symbols
#define y0 _usr_y0
#define y1 _usr_y1



void loop(){
    // Variant 2: Reduced computational intensity with coalesced memory access and fewer branches
    for (;;) {
        // Coalesce all pixel updates into a single pointer calculation
        uint16_t* pixel_base = &pixels[y0 * linesize + x0 * 4];
        
        // Vectorized-like update using direct offsets
        pixel_base[0] = 65535 - pixel_base[0];
        pixel_base[1] = 65535 - pixel_base[1];
        pixel_base[2] = 65535 - pixel_base[2];
        pixel_base[3] = 65535;

        // Merge condition check to reduce branch misprediction chances
        if (x0 == x1 && y0 == y1) break;

        // Combine error updates with minimal branching
        e2 = err;
        int update_x = (e2 > -dx);
        int update_y = (e2 < dy);

        // Apply updates without branching (conditional updates via arithmetic)
        err = err - update_x * dy + update_y * dx;
        x0 = x0 + update_x * sx;
        y0 = y0 + update_y * sy;
    }
}
