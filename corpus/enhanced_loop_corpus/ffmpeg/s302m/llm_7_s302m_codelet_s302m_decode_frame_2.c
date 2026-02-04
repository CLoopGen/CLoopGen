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
    uint32_t prev_o_val = 0;
    for (; buf_size > 5; buf_size -= 6) {
        uint32_t val1 = ((unsigned int)ff_reverse[buf[2] & 240] << 28) | (ff_reverse[buf[1]] << 20) | (ff_reverse[buf[0]] << 12) ^ prev_o_val;
        uint32_t val2 = ((unsigned int)ff_reverse[buf[5] & 240] << 28) | (ff_reverse[buf[4]] << 20) | (ff_reverse[buf[3]] << 12) ^ val1;
        *o++ = val1;
        *o++ = val2;
        prev_o_val = val2;
        buf += 6;
    }
}
