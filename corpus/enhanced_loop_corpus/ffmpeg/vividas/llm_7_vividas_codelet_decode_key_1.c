#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t keybits[32];
extern uint8_t *buf;
extern uint32_t key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_key = 0;
    for (int i = 0; i < 32; i++) {
        unsigned int p = keybits[i];
        uint8_t data = buf[p];
        int shift_amount = (i * 5 + 3) & 7;
        uint32_t bit = (data >> shift_amount) & 1U;
        local_key |= (bit << i);
    }
    key |= local_key;
}
