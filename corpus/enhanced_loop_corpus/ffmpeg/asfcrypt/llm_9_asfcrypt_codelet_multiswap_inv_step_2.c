#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint32_t keys[12];
extern uint32_t v;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i > 0; i--) {
    v *= keys[i * 2];
    v = (v >> 16) | (v << 16);
    v += keys[i];
    v = (v * 0x9E3779B9) + (v >> 12);
}
}
