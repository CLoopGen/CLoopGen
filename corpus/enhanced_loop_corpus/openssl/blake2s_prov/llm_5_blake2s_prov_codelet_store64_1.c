#include <stdio.h>

#include <inttypes.h>

extern uint64_t w;
extern uint8_t *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        uint64_t shift = 8 * i;
        p[i] = (uint8_t)(w >> shift);
        if (p[i] == 0) break;
    }
}
