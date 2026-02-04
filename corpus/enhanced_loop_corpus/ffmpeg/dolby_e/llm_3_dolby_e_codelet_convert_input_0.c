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
    // Strided memory access: process every 2nd word, forward and backward write
    int stride = 2;
    int count = (nb_words + stride - 1) / stride;
    for (i = 0; i < count; i++) {
        int index = i * stride;
        if (index >= nb_words) break;
        uint8_t *s = src + index * 3;
        uint8_t *d = dst + index * 3;
        uint32_t word = ((uint32_t)s[0] << 16) | (s[1] << 8) | s[2];
        uint32_t encrypted = word ^ key;
        // Write in reverse byte order manually without do-while
        d[0] = encrypted >> 16;
        d[1] = encrypted >> 8;
        d[2] = encrypted;
    }
}
