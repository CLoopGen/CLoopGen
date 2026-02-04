#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t value;
extern int len;
extern char bits[65];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        char bit = ((value + 1) >> (len - i - 1)) & 1 ? '1' : '0';
        bits[len + i + 1] = bit;
    }
}
