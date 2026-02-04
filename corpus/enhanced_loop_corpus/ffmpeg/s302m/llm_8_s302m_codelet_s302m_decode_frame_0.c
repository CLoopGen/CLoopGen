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
    for (; buf_size > 14; buf_size -= 14) {
        uint32_t val1 = ((unsigned int)ff_reverse[buf[2]] << 24) | (ff_reverse[buf[1]] << 16) | (ff_reverse[buf[0]] << 8);
        uint32_t val2 = ((unsigned int)ff_reverse[buf[6] & 240] << 28) | (ff_reverse[buf[5]] << 20) | (ff_reverse[buf[4]] << 12) | (ff_reverse[buf[3] & 15] << 4);
        *o++ = val1;
        *o++ = val2;

        uint32_t val3 = ((unsigned int)ff_reverse[buf[9]] << 24) | (ff_reverse[buf[8]] << 16) | (ff_reverse[buf[7]] << 8);
        uint32_t val4 = ((unsigned int)ff_reverse[buf[13] & 240] << 28) | (ff_reverse[buf[12]] << 20) | (ff_reverse[buf[11]] << 12) | (ff_reverse[buf[10] & 15] << 4);
        *o++ = val3;
        *o++ = val4;

        buf += 14;
    }
}
