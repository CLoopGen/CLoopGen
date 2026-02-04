#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t keybits[32];
extern uint8_t *buf;
extern uint32_t key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 16; i++) {
        unsigned int p0 = keybits[i * 2];
        unsigned int p1 = keybits[i * 2 + 1];
        uint8_t val0 = buf[p0];
        uint8_t val1 = buf[p1];
        key |= ((val0 >> ((i * 10 + 3) & 7)) & 1U) << (i * 2);
        key |= ((val1 >> ((i * 10 + 8) & 7)) & 1U) << (i * 2 + 1);
    }
}
