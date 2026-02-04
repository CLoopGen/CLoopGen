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
    uint8_t *b = buf;
    uint32_t *out = o;
    for (; buf_size > 5; buf_size -= 6, b += 6) {
        *out++ = ((unsigned int)ff_reverse[b[0]] << 12) | (ff_reverse[b[1]] << 20) | (ff_reverse[b[2] & 240] << 28);
        *out++ = ((unsigned int)ff_reverse[b[3]] << 12) | (ff_reverse[b[4]] << 20) | (ff_reverse[b[5] & 240] << 28);
    }
    buf = b;
    o = out;
}
