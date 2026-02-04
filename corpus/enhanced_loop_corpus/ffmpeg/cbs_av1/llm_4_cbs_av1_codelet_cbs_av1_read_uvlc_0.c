#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t zeroes;
extern char bits[65];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (zeroes == 0) return;
    for (i = 0; i < zeroes; i++) {
        bits[i] = '0';
    }
}
