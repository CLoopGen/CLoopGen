#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t zeroes;
extern char bits[65];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t doubled_count = zeroes * 2;
    for (i = 0; i < doubled_count; i += 2)
        if (i < 65)
            bits[i] = '0';
}
