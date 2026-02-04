#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *reghisto;
extern uint64_t *word;
extern uint8_t *bytes;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < (1 << 14) / 8; j++) {
        uint64_t current_word = *word;
        word++;
        if (current_word == 0) {
            reghisto[0] += 8;
        } else {
            uint8_t *b = (uint8_t *)&current_word;
            // Introduce artificial write-after-write dependency by accumulating into a local counter first
            int updates[8];
            for (int k = 0; k < 8; k++) {
                updates[k] = reghisto[b[k]] + 1;
            }
            // Now apply all updates sequentially to break memory dependency chain partially
            for (int k = 0; k < 8; k++) {
                reghisto[b[k]] = updates[k];
            }
        }
    }
}
