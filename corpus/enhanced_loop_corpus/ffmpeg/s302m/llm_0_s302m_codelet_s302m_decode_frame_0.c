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
        for (int i = 0; i < 2; i++) {
            *o++ = ((unsigned int)ff_reverse[buf[2]] << 24) | (ff_reverse[buf[1]] << 16) | (ff_reverse[buf[0]] << 8);
            *o++ = ((unsigned int)ff_reverse[buf[6] & 240] << 28) | (ff_reverse[buf[5]] << 20) | (ff_reverse[buf[4]] << 12) | (ff_reverse[buf[3] & 15] << 4);
            buf += 7;
        }
    }
}
