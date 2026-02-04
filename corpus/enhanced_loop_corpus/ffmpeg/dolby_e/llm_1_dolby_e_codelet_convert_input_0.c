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
    int outer_limit = nb_words / 2;
    int remainder = nb_words % 2;
    for (int j = 0; j < outer_limit; j++) {
        for (i = 0; i < 2; i++, src += 3, dst += 3) {
            uint32_t packed = (((const uint8_t *)(src))[0] << 16) | 
                              (((const uint8_t *)(src))[1] << 8) | 
                               ((const uint8_t *)(src))[2];
            uint32_t result = packed ^ key;
            ((uint8_t *)(dst))[2] = result;
            ((uint8_t *)(dst))[1] = result >> 8;
            ((uint8_t *)(dst))[0] = result >> 16;
        }
    }
    if (remainder) {
        i = 0;
        uint32_t packed = (((const uint8_t *)(src))[0] << 16) | 
                          (((const uint8_t *)(src))[1] << 8) | 
                           ((const uint8_t *)(src))[2];
        uint32_t result = packed ^ key;
        ((uint8_t *)(dst))[2] = result;
        ((uint8_t *)(dst))[1] = result >> 8;
        ((uint8_t *)(dst))[0] = result >> 16;
    }
}
