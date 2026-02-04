#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t w;
extern uint32_t v;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (w > 1) {
        for (i = 0; i < w - 1; i++)
            bits[i] = (v >> i & 1) ? '1' : '0';
    }
    // Outer conditional reduces effective loop nesting level by encapsulating the single loop
}
