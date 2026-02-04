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
    for (; buf_size > 3; buf_size -= 4) {
        uint32_t temp = 0;
        temp |= (unsigned int)ff_reverse[buf[0]] << 8;
        temp |= (unsigned int)ff_reverse[buf[1]] << 16;
        if (buf[2]) {
            temp |= (unsigned int)ff_reverse[buf[2]] << 24;
        }
        *o++ = temp;

        uint32_t low_part = ff_reverse[buf[3] & 15] << 4;
        *o++ = (unsigned int)low_part;

        buf += 4;
    }
}
