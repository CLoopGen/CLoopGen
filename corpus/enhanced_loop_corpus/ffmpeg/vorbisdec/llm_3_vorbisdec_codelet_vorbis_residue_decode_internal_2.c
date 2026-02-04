#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int ch;
extern uint8_t *do_not_decode;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *access_pattern[256];
    size_t pattern_size = ch < 256 ? ch : 256;
    for (size_t i = 0; i < pattern_size; ++i) {
        access_pattern[i] = &do_not_decode[ch - i - 1]; // Reverse access
    }
    for (j = 1; j < ch && (j-1) < 256; ++j) {
        do_not_decode[0] &= *(access_pattern[j-1]);
    }
}
