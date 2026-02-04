#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t keybits[32];
extern uint8_t *buf;
extern uint32_t key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 64; i += 2) {
        unsigned int p = keybits[i / 2];
        uint8_t shifted = buf[p] >> ((i * 5 + 3) & 7);
        key |= ((shifted & 1U) << i);
        if (i + 1 < 32) {
            key |= (((buf[p] >> ((i * 5 + 8) & 7)) & 1U) << (i + 1));
        }
    }
}
