#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t range_min;
extern uint32_t value;
extern int len;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        if (range_min + i != value) {
            bits[i] = '1';
            continue;
        }
        bits[i] = '0';
    }
}
