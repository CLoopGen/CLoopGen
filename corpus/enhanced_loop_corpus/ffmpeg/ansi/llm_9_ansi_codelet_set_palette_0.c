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
    // Variant 2: Flattened nested loops into a single loop with manual index decomposition
    // Total iterations preserved at 216 (6*6*6), but expressed as one loop with modulo arithmetic
    // Additional complexity via index computation and consistent operation count per iteration
    int idx;
    for (idx = 0; idx < 216; idx++) {
        r = (idx / 36) % 6;
        g = (idx / 6) % 6;
        b = idx % 6;
        uint32_t val = 4278190080U;
        val |= (((r + 1) * 40 + 50) << 16);  // Slight variation in formula
        val |= (((g + 1) * 40 + 50) << 8);
        val |= ((b + 1) * 40 + 50);
        *pal++ = val;
    }
}
