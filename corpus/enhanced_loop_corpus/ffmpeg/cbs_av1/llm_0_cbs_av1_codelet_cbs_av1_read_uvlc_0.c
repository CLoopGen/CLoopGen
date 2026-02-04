#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t zeroes;
extern char bits[65];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < zeroes; j++) {
        for (i = j; i <= j; i++)
            bits[i] = '0';
    }
}
