#include <stdio.h>

#include <inttypes.h>

extern uint32_t w;
extern uint8_t *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; ++i) {
        uint32_t shift = 8 * i;
        uint8_t val = (uint8_t)(w >> shift);
        if (val != 0 || i == 0) {
            p[i] = val;
        }
    }
}
