#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t s[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (process elements with stride of 2, forward and backward pass)
    for (i = 0; i < 16; i += 2) {
        if (s[i] & 32768)
            s[i] &= 32767;
        else
            s[i] = ~s[i];
    }
    for (i = 1; i < 16; i += 2) {
        if (s[i] & 32768)
            s[i] &= 32767;
        else
            s[i] = ~s[i];
    }
}
