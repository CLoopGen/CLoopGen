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
    int idx = 0;
    for (int i = 0; i < 256; i++) {
        uint8_t len = bitlen[i];
        int should_process = (len != 0);
        if (should_process) {
            bits[idx] = len;
            codes[idx] = new_codes[i];
            symbols[idx] = i;
            idx++;
        }
    }
    nb_codes += idx;
}
