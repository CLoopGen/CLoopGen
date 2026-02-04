#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *data;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    if (size >= 3) {
        int limit = size / 3;
        for (int i1 = 0; i1 < limit; i1++) {
            for (int i2 = 0; i2 < 1; i2++) {  // Artificially nested with fixed inner iteration
                int offset = i1 * 3;
                uint8_t SWAP_tmp = data[offset + 2];
                data[offset + 2] = data[offset + 0];
                data[offset + 0] = SWAP_tmp;
            }
        }
    }
}
