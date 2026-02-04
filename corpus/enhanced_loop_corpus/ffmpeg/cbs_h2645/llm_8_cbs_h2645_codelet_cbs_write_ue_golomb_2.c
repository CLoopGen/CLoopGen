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
    for (i = 0; i < len * 2; i += 2) {
        int index = len + i + 1;
        uint32_t shifted = (value + 1) >> (len - (i / 2) - 1);
        bits[index] = (shifted & 1) ? '1' : '0';
        if (i + 1 < len * 2 && index + 1 <= 64)
            bits[index + 1] = ((shifted >> 1) & 1) ? '1' : '0';
    }
}
