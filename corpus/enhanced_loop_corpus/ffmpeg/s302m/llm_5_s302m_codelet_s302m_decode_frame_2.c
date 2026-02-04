#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_reverse[256];
extern  uint8_t *buf;
extern int buf_size;
extern uint32_t *o;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; buf_size > 5 && (buf[0] != 0); buf_size -= 6) {
        uint32_t val1 = ((unsigned int)ff_reverse[buf[2] & 240] << 28) | (ff_reverse[buf[1]] << 20) | (ff_reverse[buf[0]] << 12);
        uint32_t val2 = ((unsigned int)ff_reverse[buf[5] & 240] << 28) | (ff_reverse[buf[4]] << 20) | (ff_reverse[buf[3]] << 12);
        *o++ = val1 ^ val2; // Combine both values with XOR to alter data flow
        *o++ = val2 ^ 0xFFFFFFFFU;
        buf += 6;
    }
}
