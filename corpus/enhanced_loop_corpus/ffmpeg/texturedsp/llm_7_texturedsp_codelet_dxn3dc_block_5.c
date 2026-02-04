#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t buffer[16][2]; // Local buffer to break memory dependencies
    uint8_t *addr[16];

    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            int idx = y * 4 + x;
            addr[idx] = dst + x * 4 + y * stride;
            buffer[idx][0] = addr[idx][1]; // Read early: breaks WAW and WAR
            buffer[idx][1] = addr[idx][0];
        }
    }

    // Second pass: write swapped values, introducing loop-carried dependency via ordering
    for (int i = 0; i < 16; i++) {
        addr[i][0] = buffer[i][0];
        addr[i][1] = buffer[i][1];
    }
}
