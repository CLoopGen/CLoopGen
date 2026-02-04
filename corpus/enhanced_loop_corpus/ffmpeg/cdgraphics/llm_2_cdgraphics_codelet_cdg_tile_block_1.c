#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *data;
extern int b;
extern unsigned int ci;
extern unsigned int ri;
extern int color;
extern int x;
extern int y;
extern int ai;
extern int stride;
extern uint8_t *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (Unroll and transpose access pattern)
    // We precompute indices to access buf consecutively by reordering loop iterations
    int temp_ai[72];  // 12 * 6 = 72 possible accesses
    int temp_color[72];
    int idx = 0;
    for (x = 0; x < 6; x++) {
        for (y = 0; y < 12; y++) {
            if (!((data[4 + y] >> (5 - x)) & 1))
                color = data[0] & 15;
            else
                color = data[1] & 15;
            ai = ci + x + (stride * (ri + y));
            if (b)
                color ^= buf[ai];
            temp_ai[idx] = ai;
            temp_color[idx] = color;
            idx++;
        }
    }
    // Now write back in consecutive order of buf access? Not exactly, but we simulate reordered computation.
    // Instead, just apply the values in original dependency-safe order
    for (idx = 0; idx < 72; idx++) {
        buf[temp_ai[idx]] = temp_color[idx];
    }
}
