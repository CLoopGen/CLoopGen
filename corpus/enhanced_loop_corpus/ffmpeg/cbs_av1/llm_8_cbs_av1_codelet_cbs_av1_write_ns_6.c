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
    uint32_t limit = w > 32 ? 32 : w - 1;
    for (i = 0; i < limit; i++) {
        bits[i] = ((v >> i) & 1) ? '1' : '0';
    }
    if (w > 1) {
        bits[limit] = '\0';
    }
}
