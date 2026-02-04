#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t keybits[32];
extern uint8_t *buf;
extern uint32_t key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < 32; i += 2) {
            if (i + k < 32) {
                unsigned int p = keybits[i + k];
                key |= ((buf[p] >> (((i + k) * 5 + 3) & 7)) & 1U) << (i + k);
            }
        }
    }
}
