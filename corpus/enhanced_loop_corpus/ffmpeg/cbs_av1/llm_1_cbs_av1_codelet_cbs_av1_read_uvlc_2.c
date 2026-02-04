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
    for (int outer = 0; outer < 2 && j < zeroes; outer++) {
        for (j = outer * (zeroes / 2); j < ((outer + 1) * (zeroes / 2)) && j < zeroes; j++)
            bits[i++] = (bits_value >> (zeroes - j - 1) & 1) ? '1' : '0';
    }
}
