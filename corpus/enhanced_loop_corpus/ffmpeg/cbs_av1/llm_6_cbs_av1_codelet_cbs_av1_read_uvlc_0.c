#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t zeroes;
extern char bits[65];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_zeroes = zeroes;
    char temp_bits[65];
    for (i = 0; i < local_zeroes; i++) {
        temp_bits[i] = '0';
    }
    for (i = 0; i < local_zeroes; i++) {
        bits[i] = temp_bits[i];
    }
}
