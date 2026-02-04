#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t dst_color[4];
extern uint8_t rgba_color[4];
extern uint8_t rgba_map[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern (simulated by unrolling and stride of 2 with wrap-around logic)
    // This variant accesses elements in a non-sequential but deterministic strided manner
    for (i = 0; i < 4; i += 2) {
        dst_color[rgba_map[i]] = rgba_color[i];
        if (i + 1 < 4) {
            dst_color[rgba_map[i + 1]] = rgba_color[i + 1];
        }
    }
}
