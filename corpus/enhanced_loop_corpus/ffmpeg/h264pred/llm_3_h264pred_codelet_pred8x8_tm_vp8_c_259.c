#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern  uint8_t *cm;
extern uint8_t *top;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 8; y++) {
        // Use strided access into 'top' array with a non-unit stride (simulating scattered read)
        const uint8_t *cm_in = cm + src[-1];
        int i;
        for (i = 0; i < 8; ++i) {
            // Simulate irregular but deterministic access pattern (stride of 2, modulo 16 for coverage)
            int idx = (i * 2) % 16; // Ensures within bounds if top is at least 16 bytes
            src[i] = cm_in[top[idx]];
        }
        src += stride;
    }
}
