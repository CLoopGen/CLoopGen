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
    if (buf_size <= 6) return;
    do {
        *o++ = ((unsigned int)ff_reverse[buf[2]] << 24) | (ff_reverse[buf[1]] << 16) | (ff_reverse[buf[0]] << 8);
        *o++ = ((unsigned int)ff_reverse[buf[6] & 240] << 28) | (ff_reverse[buf[5]] << 20) | (ff_reverse[buf[4]] << 12) | (ff_reverse[buf[3] & 15] << 4);
        buf += 7;
        buf_size -= 7;
    } while (buf_size > 6);
}
