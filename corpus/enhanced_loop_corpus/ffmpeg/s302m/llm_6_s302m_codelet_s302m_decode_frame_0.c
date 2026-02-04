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
    uint32_t temp1, temp2;
    for (; buf_size > 6; buf_size -= 7) {
        temp1 = ((unsigned int)ff_reverse[buf[0]] << 8) | (ff_reverse[buf[1]] << 16);
        temp2 = (ff_reverse[buf[2]] << 24);
        *o++ = temp1 | temp2;
        temp1 = (ff_reverse[buf[3] & 15] << 4) | (ff_reverse[buf[4]] << 12);
        temp2 = (ff_reverse[buf[5]] << 20) | ((ff_reverse[buf[6] & 240]) << 28);
        *o++ = temp1 | temp2;
        buf += 7;
    }
}
