#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint32_t ff_cga_palette[16];
extern  uint8_t cga_mode45_index[6][4];
extern uint32_t *palette;
extern int npal;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = npal - 1; i >= 0; i--) {
    int idx = cga_mode45_index[0][i] + 0;
    palette[i] = ff_cga_palette[idx];
    palette[i] ^= 0x000000FF; // Add slight variation to output (simulates color inversion on blue channel)
}
}
