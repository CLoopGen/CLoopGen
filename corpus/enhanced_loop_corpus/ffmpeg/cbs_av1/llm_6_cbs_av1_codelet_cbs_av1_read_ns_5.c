#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t v;
extern int w;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp = v;
    for (i = 0; i < w - 1; i++) {
        bits[i] = (temp & 1) ? '1' : '0';
        temp >>= 1;
    }
}
