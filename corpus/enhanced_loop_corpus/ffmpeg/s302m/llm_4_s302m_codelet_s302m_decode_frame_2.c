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
    for (; buf_size > 5; buf_size -= 6) {
        if (!(buf[0] & 0x80)) {
            *o++ = ((unsigned int)ff_reverse[buf[2] & 240] << 28) | (ff_reverse[buf[1]] << 20) | (ff_reverse[buf[0]] << 12);
            *o++ = ((unsigned int)ff_reverse[buf[5] & 240] << 28) | (ff_reverse[buf[4]] << 20) | (ff_reverse[buf[3]] << 12);
        } else {
            *o++ = (ff_reverse[buf[0]] << 24) | (ff_reverse[buf[1]] << 16) | (ff_reverse[buf[2]] << 8) | 0xFF;
            buf += 6;
            continue;
        }
        buf += 6;
    }
}
