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
    for (j = 0; j < zeroes && i < 65; j++) {
        uint32_t shift_amount = zeroes - j - 1;
        char bit_char = ((bits_value >> shift_amount) & 1) ? '1' : '0';
        bits[i] = bit_char;
        i++;
    }
}
