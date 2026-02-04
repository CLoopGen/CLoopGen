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
    int step = 1;
    for (j = 0; j < zeroes; j += step) {
        for (int unroll = 0; unroll < step && (j + unroll) < zeroes; unroll++) {
            int idx = j + unroll;
            bits[i++] = (bits_value >> (zeroes - idx - 1) & 1) ? '1' : '0';
        }
    }
}
