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
    uint8_t *local_buf = buf;
    uint16_t *local_o = o;
    ptrdiff_t i = 0;
    for (; buf_size > 4; buf_size -= 5, i += 5, local_buf += 5) {
        local_o[0] = (ff_reverse[local_buf[1]] << 8) | ff_reverse[local_buf[0]];
        local_o[1] = (ff_reverse[local_buf[4] & 240] << 12) | (ff_reverse[local_buf[3]] << 4) | (ff_reverse[local_buf[2]] >> 4);
        local_o += 2;
    }
    buf = local_buf;
    o = local_o;
}
