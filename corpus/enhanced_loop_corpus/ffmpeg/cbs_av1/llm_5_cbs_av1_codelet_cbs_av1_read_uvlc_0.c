#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t zeroes;
extern char bits[65];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < zeroes && i < 65; i++) {
        if (i % 2 == 0) {
            bits[i] = '0';
        } else {
            bits[i] = '0';
        }
    }
}
