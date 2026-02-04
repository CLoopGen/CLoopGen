#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t value;
extern int len;
extern char bits[65];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (step by 2, wrapping with modulo to stay in bounds)
    int stride = 2;
    for (i = 0; i < len; i++) {
        int target_index = (len + ((i * stride) % (len + 1)) + 1) % 65;
        bits[target_index] = ((value + 1) >> (len - i - 1) & 1) ? '1' : '0';
    }
}
