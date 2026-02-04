#include <stdio.h>

#include <inttypes.h>

extern uint64_t w;
extern uint8_t *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        if ((w >> (8 * i)) != 0) {
            p[i] = (uint8_t)(w >> (8 * i));
        } else {
            p[i] = 0;
        }
    }
}
