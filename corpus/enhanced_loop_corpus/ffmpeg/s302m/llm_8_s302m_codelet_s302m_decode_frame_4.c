#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_reverse[256];
extern  uint8_t *buf;
extern int buf_size;
extern uint16_t *o;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; buf_size > 9; buf_size -= 10) {
        *o++ = (ff_reverse[buf[1]] << 8) | ff_reverse[buf[0]];
        *o++ = (ff_reverse[buf[4] & 240] << 12) | (ff_reverse[buf[3]] << 4) | (ff_reverse[buf[2]] >> 4);
        *o++ = (ff_reverse[buf[6]] << 8) | ff_reverse[buf[5]];
        *o++ = (ff_reverse[buf[9] & 240] << 12) | (ff_reverse[buf[8]] << 4) | (ff_reverse[buf[7]] >> 4);
        buf += 10;
    }
}
