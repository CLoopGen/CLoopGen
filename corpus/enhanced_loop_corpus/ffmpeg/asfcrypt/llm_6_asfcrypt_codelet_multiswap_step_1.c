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
    for (i = 1; i < 5; i++) {
        temp = (temp >> 16) | (temp << 16);
        temp *= keys[i];
    }
    v = temp;
}
