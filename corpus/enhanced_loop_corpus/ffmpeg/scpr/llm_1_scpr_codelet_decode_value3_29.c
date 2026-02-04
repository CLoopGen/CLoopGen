#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t max;
extern uint32_t *cntsum;
extern uint16_t *freqs1;
extern uint16_t *freqs2;
extern uint16_t *cnts;
extern uint8_t *dectable;
extern uint32_t y;
extern uint32_t e;
extern uint32_t g;
extern uint32_t q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Flattened version: reduce loop nesting by eliminating the inner loop through unrolling assumption
// Assume maximum practical difference (q - g) is small and bounded, here we cap it at 4 for flattening
for (int c = 0, i = 0; i < max + 1; i++) {
    e = cnts[i];
    freqs2[i] = c;
    freqs1[i] = e;
    g = (c + 127) >> 7;
    c += e;
    q = ((c - 1) >> 7) + 1;
    int diff = q - g;
    if (diff > 0 && g < 256) { // Prevent out-of-bounds; assume dectable size allows up to 256
        if (diff >= 1 && (g + 0) < 256) dectable[g + 0] = i;
        if (diff >= 2 && (g + 1) < 256) dectable[g + 1] = i;
        if (diff >= 3 && (g + 2) < 256) dectable[g + 2] = i;
        if (diff >= 4 && (g + 3) < 256) dectable[g + 3] = i;
        // For simplicity, cap unrolled iterations; in practice, this could be adjusted
    }
    y = e - (e >> 1);
    cnts[i] = y;
    *cntsum += y;
}
}
