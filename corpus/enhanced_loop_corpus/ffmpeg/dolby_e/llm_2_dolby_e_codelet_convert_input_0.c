#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nb_words;
extern int key;
extern uint8_t *src;
extern uint8_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nb_words; i++) {
        uint8_t *s = &src[i * 3];
        uint8_t *d = &dst[i * 3];
        uint32_t packed = ((uint32_t)s[0] << 16) | (s[1] << 8) | s[2];
        uint32_t result = packed ^ key;
        d[2] = result;
        d[1] = result >> 8;
        d[0] = result >> 16;
    }
}
