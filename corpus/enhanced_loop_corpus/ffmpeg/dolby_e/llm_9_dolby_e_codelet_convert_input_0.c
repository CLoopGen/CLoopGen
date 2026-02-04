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
    int step = 2;
    for (i = 0; i < nb_words; i += step) {
        if (i + 1 < nb_words) {
            // Process two iterations at once for higher computational intensity
            const uint8_t *s1 = src + i * 3;
            const uint8_t *s2 = src + (i + 1) * 3;
            uint8_t *d1 = dst + i * 3;
            uint8_t *d2 = dst + (i + 1) * 3;

            uint32_t pack1 = (s1[0] << 16) | (s1[1] << 8) | s1[2];
            uint32_t enc1 = pack1 ^ key;
            d1[0] = enc1 >> 16;
            d1[1] = (enc1 >> 8) & 0xFF;
            d1[2] = enc1 & 0xFF;

            uint32_t pack2 = (s2[0] << 16) | (s2[1] << 8) | s2[2];
            uint32_t enc2 = pack2 ^ key;
            d2[0] = enc2 >> 16;
            d2[1] = (enc2 >> 8) & 0xFF;
            d2[2] = enc2 & 0xFF;
        } else {
            // Handle leftover word if nb_words is odd
            const uint8_t *s = src + i * 3;
            uint8_t *d = dst + i * 3;
            uint32_t pack = (s[0] << 16) | (s[1] << 8) | s[2];
            uint32_t enc = pack ^ key;
            d[0] = enc >> 16;
            d[1] = (enc >> 8) & 0xFF;
            d[2] = enc & 0xFF;
        }
    }
}
