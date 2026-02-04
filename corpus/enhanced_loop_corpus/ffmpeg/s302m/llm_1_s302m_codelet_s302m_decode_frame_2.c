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
    for (int i = 0; buf_size > 5; buf_size -= 6, i++) {
        for (int j = 0; j < 1; j++) {
            *o++ = ((unsigned int)ff_reverse[buf[2] & 240] << 28) | (ff_reverse[buf[1]] << 20) | (ff_reverse[buf[0]] << 12);
            *o++ = ((unsigned int)ff_reverse[buf[5] & 240] << 28) | (ff_reverse[buf[4]] << 20) | (ff_reverse[buf[3]] << 12);
            buf += 6;
        }
    }
}
