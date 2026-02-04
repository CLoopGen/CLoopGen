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
    // Variant 2: Consecutive forward write starting from a base offset
    int base_offset = len + 1;
    for (i = 0; i < len; i++) {
        // Ensure consecutive writes into bits[] array
        bits[base_offset + i] = ((value + 1) >> (len - i - 1) & 1) ? '1' : '0';
    }
}
