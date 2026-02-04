#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t s[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    uint16_t temp[16];
    for (i = 0; i < 16; ++i) {
        temp[i] = s[i];
        if (temp[i] & 32768)
            s[i] = temp[i] & 32767;
        else
            s[i] = ~temp[i];
    }
}
