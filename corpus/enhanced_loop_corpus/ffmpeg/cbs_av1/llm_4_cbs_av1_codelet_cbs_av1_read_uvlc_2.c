#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t zeroes;
extern uint32_t bits_value;
extern char bits[65];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < zeroes; j++) {
        char bit_char = '0';
        if ((bits_value >> (zeroes - j - 1)) & 1) {
            bit_char = '1';
        }
        bits[i++] = bit_char;
    }
}
