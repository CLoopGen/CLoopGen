#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t keybits[32];
extern uint8_t *buf;
extern uint32_t key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++) {
        for (int i = 0; i < 32; i++) {
            unsigned int p = keybits[i];
            key |= ((buf[p] >> ((i * 5 + 3) & 7)) & 1U) << i;
        }
    }
}
