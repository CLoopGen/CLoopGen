#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t keybits[32];
extern uint8_t *buf;
extern uint32_t key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_key = key;
    for (int i = 0; i < 32; i++) {
        unsigned int p = keybits[i];
        uint8_t shifted = buf[p] >> ((i * 5 + 3) & 7);
        temp_key |= ((shifted & 1U) << i);
    }
    key = temp_key;
}
