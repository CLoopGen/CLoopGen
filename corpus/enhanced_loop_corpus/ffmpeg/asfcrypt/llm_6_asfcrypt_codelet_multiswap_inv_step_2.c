#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint32_t keys[12];
extern uint32_t v;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp = v;
    for (i = 4; i > 0; i--) {
        temp *= keys[i];
        temp = (temp >> 16) | (temp << 16);
    }
    v = temp;
}
