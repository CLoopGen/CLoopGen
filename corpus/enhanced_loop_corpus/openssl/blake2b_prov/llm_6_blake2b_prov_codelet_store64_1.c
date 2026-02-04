#include <stdio.h>

#include <inttypes.h>

extern uint64_t w;
extern uint8_t *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp = w;
    for (i = 0; i < 8; i++) {
        p[i] = (uint8_t)temp;
        temp >>= 8;
    }
}
