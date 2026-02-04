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
    for (; buf_size > 5; buf_size -= 6) {
        temp1 = ((unsigned int)ff_reverse[buf[2] & 240] << 28) | (ff_reverse[buf[1]] << 20) | (ff_reverse[buf[0]] << 12);
        temp2 = ((unsigned int)ff_reverse[buf[5] & 240] << 28) | (ff_reverse[buf[4]] << 20) | (ff_reverse[buf[3]] << 12);
        *o++ = temp1;
        *o++ = temp2;
        buf += 6;
    }
}
