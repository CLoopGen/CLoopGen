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
    for (; buf_size > 11; buf_size -= 12) {
        uint32_t v1 = ((unsigned int)ff_reverse[buf[2] & 240] << 28) | (ff_reverse[buf[1]] << 20) | (ff_reverse[buf[0]] << 12);
        uint32_t v2 = ((unsigned int)ff_reverse[buf[5] & 240] << 28) | (ff_reverse[buf[4]] << 20) | (ff_reverse[buf[3]] << 12);
        uint32_t v3 = ((unsigned int)ff_reverse[buf[8] & 240] << 28) | (ff_reverse[buf[7]] << 20) | (ff_reverse[buf[6]] << 12);
        uint32_t v4 = ((unsigned int)ff_reverse[buf[11] & 240] << 28) | (ff_reverse[buf[10]] << 20) | (ff_reverse[buf[9]] << 12);
        *o++ = v1;
        *o++ = v2;
        *o++ = v3;
        *o++ = v4;
        buf += 12;
    }
}
