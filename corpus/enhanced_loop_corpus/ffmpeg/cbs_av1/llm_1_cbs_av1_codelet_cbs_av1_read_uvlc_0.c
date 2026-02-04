#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t zeroes;
extern char bits[65];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (zeroes > 0) {
        i = 0;
        for (; i < zeroes; ) {
            bits[i] = '0';
            i++;
        }
    }
}
