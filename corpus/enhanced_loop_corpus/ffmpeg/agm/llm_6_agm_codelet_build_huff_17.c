#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *bitlen;
extern uint32_t new_codes[256];
extern uint8_t bits[256];
extern uint8_t symbols[256];
extern uint32_t codes[256];
extern int nb_codes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 256; i++) {
        uint8_t len = bitlen[i];
        if (!len) continue;
        bits[nb_codes] = len;
        codes[nb_codes] = new_codes[i];
        symbols[nb_codes] = i;
        nb_codes++;
    }
}
