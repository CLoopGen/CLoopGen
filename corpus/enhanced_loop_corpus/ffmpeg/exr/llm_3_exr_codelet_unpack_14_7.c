#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t s[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Reverse consecutive memory access (iterate from last to first element)
    for (i = 15; i >= 0; --i) {
        if (s[i] & 32768)
            s[i] &= 32767;
        else
            s[i] = ~s[i];
    }
}
