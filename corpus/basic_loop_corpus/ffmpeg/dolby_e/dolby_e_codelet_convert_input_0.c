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
for (i = 0; i < nb_words; i++ , src += 3 , dst += 3)
    do {
        ((uint8_t *)(dst))[2] = (((((const uint8_t *)(src))[0] << 16) | (((const uint8_t *)(src))[1] << 8) | ((const uint8_t *)(src))[2]) ^ key);
        ((uint8_t *)(dst))[1] = (((((const uint8_t *)(src))[0] << 16) | (((const uint8_t *)(src))[1] << 8) | ((const uint8_t *)(src))[2]) ^ key) >> 8;
        ((uint8_t *)(dst))[0] = (((((const uint8_t *)(src))[0] << 16) | (((const uint8_t *)(src))[1] << 8) | ((const uint8_t *)(src))[2]) ^ key) >> 16;
    } while (0);

}
