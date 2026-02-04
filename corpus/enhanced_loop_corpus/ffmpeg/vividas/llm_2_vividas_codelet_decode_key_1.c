#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t keybits[32];
extern uint8_t *buf;
extern uint32_t key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 32; i++) {
        unsigned int p = keybits[i];
        int index = (p + i) & 255; // Consecutive-like access with offset
        key |= ((buf[index] >> ((i * 5 + 3) & 7)) & 1U) << i;
    }
}
