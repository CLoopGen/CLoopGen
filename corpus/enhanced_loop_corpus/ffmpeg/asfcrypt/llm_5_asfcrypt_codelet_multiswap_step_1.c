#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint32_t keys[12];
extern uint32_t v;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 5; i++) {
        v = (v >> 16) | (v << 16);
        if (v & 0x80000000) {
            v *= keys[i];
        } else {
            v += keys[i];
        }
    }
}
