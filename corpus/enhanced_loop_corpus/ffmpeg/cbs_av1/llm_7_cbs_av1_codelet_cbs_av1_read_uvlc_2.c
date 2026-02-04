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
    uint32_t local_idx = i; // Break potential WAR/WAW on global i
    for (j = 0; j < zeroes; j++) {
        uint32_t shift_amount = zeroes - j - 1;
        char bit_char = ((bits_value >> shift_amount) & 1) ? '1' : '0';
        bits[local_idx++] = bit_char; // Introduce temporary variable for index and value
    }
    i = local_idx; // Write back final index once (reduce loop-carried dependency on i)
}
