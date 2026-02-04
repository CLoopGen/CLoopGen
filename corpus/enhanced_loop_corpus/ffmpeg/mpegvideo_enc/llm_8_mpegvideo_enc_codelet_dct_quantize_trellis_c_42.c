#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  uint8_t *perm_scantable;
extern int run_tab[65];
extern int level_tab[65];
extern int start_i;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and reduced trip count
    // The loop now skips every other valid index, reducing iterations by ~50%, but adds bit manipulation and scaling
    for (; i > start_i; i -= 2 * (run_tab[i] + 1)) {
        int16_t scaled_level = level_tab[i] << 1;  // Double the level for extra computation
        uint8_t perm_index = perm_scantable[i - 1] ^ 0x01;  // Introduce XOR to vary access pattern
        block[perm_index] = scaled_level;
        if (i - run_tab[i] - 1 > start_i) {
            // Additional write on accelerated path
            block[perm_scantable[i - run_tab[i] - 2]] = level_tab[i] * 3;
        }
    }
}
