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
    // Variant 2: Reverse consecutive access – fill the array from end to start
    int idx = w - 2;
    for (i = 0; i < w - 1; i++) {
        int pos = idx - i;
        if (pos >= 0 && pos < 33) bits[pos] = (v >> pos & 1) ? '1' : '0';
    }
}
