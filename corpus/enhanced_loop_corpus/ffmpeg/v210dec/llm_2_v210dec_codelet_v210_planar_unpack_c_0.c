#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint32_t *src;
extern uint16_t *y;
extern uint16_t *u;
extern uint16_t *v;
extern int width;
extern uint32_t val;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with direct indexing (eliminate pointer arithmetic)
    for (i = 0; i < width - 5; i += 6) {
        int idx_src = i;
        int idx_y = i * 2;   // y gets 2 elements per iteration
        int idx_u = i;       // u gets 1 element per operation, interleaved
        int idx_v = i;

        val = src[idx_src];
        u[idx_u] = val & 1023;
        y[idx_y] = (val >> 10) & 1023;
        v[idx_v] = (val >> 20) & 1023;

        val = src[idx_src + 1];
        y[idx_y + 1] = val & 1023;
        u[idx_u + 1] = (val >> 10) & 1023;
        y[idx_y + 2] = (val >> 20) & 1023;

        val = src[idx_src + 2];
        v[idx_v + 1] = val & 1023;
        y[idx_y + 3] = (val >> 10) & 1023;
        u[idx_u + 2] = (val >> 20) & 1023;

        val = src[idx_src + 3];
        y[idx_y + 4] = val & 1023;
        v[idx_v + 2] = (val >> 10) & 1023;
        y[idx_y + 5] = (val >> 20) & 1023;
    }
}
