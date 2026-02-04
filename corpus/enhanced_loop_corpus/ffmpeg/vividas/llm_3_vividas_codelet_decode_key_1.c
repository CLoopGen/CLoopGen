#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t keybits[32];
extern uint8_t *buf;
extern uint32_t key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 32; i += 4) { // Strided access: step by 4
        key |= ((buf[keybits[i + 0]] >> (((i + 0) * 5 + 3) & 7)) & 1U) << (i + 0);
        key |= ((buf[keybits[i + 1]] >> (((i + 1) * 5 + 3) & 7)) & 1U) << (i + 1);
        key |= ((buf[keybits[i + 2]] >> (((i + 2) * 5 + 3) & 7)) & 1U) << (i + 2);
        key |= ((buf[keybits[i + 3]] >> (((i + 3) * 5 + 3) & 7)) & 1U) << (i + 3);
    }
}
