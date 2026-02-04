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
    for (; buf_size > 4; buf_size -= 5) {
        uint16_t val1 = ff_reverse[buf[0]];
        uint16_t val2 = ff_reverse[buf[1]];
        uint16_t val3 = ff_reverse[buf[2]];
        uint16_t val4 = ff_reverse[buf[3]];
        uint16_t val5 = ff_reverse[buf[4] & 240];
        *o++ = (val2 << 8) | val1;
        *o++ = (val5 << 12) | (val4 << 4) | (val3 >> 4);
        buf += 5;
    }
}
